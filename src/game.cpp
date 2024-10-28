#include "../include/game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <cstdlib>
#include <functional>
#include <spdlog/spdlog.h>
#include <boost/serialization/config.hpp>
#include <string>
#include <sys/stat.h>

std::string game::getErrorName(Error error) {
    static const std::unordered_map<Error, const char*> names = {
        { Error::SUCCESS,   "success" },
        { Error::UNKNOWN,   "unknown"},
        { Error::SDL_INIT,  "sdl_init"},
        { Error::GAME_INIT, "game_init" },
        { Error::SDL_ERROR, "sdl_error" },
        { Error::ILLEGAL_GET, "illegal_get" },
    };
    auto it = names.find(error);
    if (it != names.end())
        return it->second;
    return "<undefined>";
}
std::string game::getErrorName(int error) {
    return getErrorName((game::Error)error);
}
int game::m_initsdl() {
    spdlog::info("Starting SDL2 initialization...");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        spdlog::critical("SDL2 initialization failed: {}", SDL_GetError());
        return game::SDL_INIT;
    }
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        spdlog::critical("SDL2 Image initialization failed: {}", IMG_GetError());
        return game::SDL_INIT;
    }
    if (TTF_Init() != 0) {
        spdlog::critical("SDL2 ttf initialization failed: {}", TTF_GetError());
        return game::SDL_INIT;
    }
    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        spdlog::critical("SDL2 Mix initialization failed: {}", Mix_GetError());         
        return game::SDL_INIT;
    }
    spdlog::info("SDL2 initialization successful!");
    return 0;
}
int game::m_initGame() {
    spdlog::info("Starting game initialization...");
    // Create the window
    m_window = SDL_CreateWindow("Game", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                1200, 
                                800, 
                                SDL_WINDOW_SHOWN);
    if (m_window == nullptr) {
        spdlog::critical("Error creating the main window: {}", SDL_GetError());
        return game::SDL_ERROR;
    }
    // Create the window surface
    m_renderer = SDL_CreateRenderer(m_window, 
                                    -1, 
                                    SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        spdlog::critical("Error creating the main window renderer: {}", SDL_GetError());
        return game::SDL_ERROR;
    }       
    spdlog::info("Game initialized successfully!");
    return game::SUCCESS;
}
int game::m_start() {
    // Initialize SDL2 and the game
    int status = 0;
    status = m_initsdl();
    if (status != game::SUCCESS)
        panic(status, "Error in SDL2 initialization");
    status = m_initGame();
    spdlog::debug("Game init finished");
    if (status != game::SUCCESS)
        panic(status, "Error in game initialization");
    
    // Start the game loop
    bool quit = false;
    while (!quit) {
        int status = 0;
        status = m_gameTick();
        if (status != game::SUCCESS) {
            panic(status, "Error in the game loop");
        }
        status = m_render();
        if (status != game::SUCCESS) {
            panic(status, "Error in the rendering");
            break;
        }
        SDL_Delay(200);
    }
    spdlog::debug("Game loop ended");
    return game::SUCCESS;
}
int game::m_render() {
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    
    // Render
    for (auto callback : m_renderCallbacks) {
        callback();
    }

    SDL_RenderPresent(m_renderer);
    return game::SUCCESS;
}
void game::m_cleanup(int code) {
    spdlog::info("Starting the SDL2 cleanup...");
    // Free the memory
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    // Cleanup SDL
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    spdlog::info("Cleaned up!");
    exit(code);
}
void game::stop() {
    spdlog::info("Stopping the game... Goodbye!");
    m_cleanup();
}
void game::start() {
    m_start();
}
int game::m_gameTick() {
    static SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                spdlog::debug("Quit event");
                stop();
                break;
            case SDL_MOUSEMOTION:
                m_mousePos = { e.motion.x, e.motion.y };
                break;
            default:
                // spdlog::debug("Unknown event: {}", e.type);
                break;
        }
    }
    return game::SUCCESS;
}
void game::panic(int errcode, std::string message) {
    spdlog::critical("A critical error has occured in the application:\nname: {}\ncode: {}\nmessage: {}", game::getErrorName(errcode), errcode, message);
    m_cleanup(errcode);
}
void game::panic(int errcode) {
    spdlog::critical("A critical error has occured in the application:\nname: {}\ncode: {}", game::getErrorName(errcode), errcode);
    m_cleanup(errcode);
}
void game::panic() {
    spdlog::critical("A critical error has occured in the application");
    m_cleanup(Error::UNKNOWN);
}

inline const SDL_Point& game::getMousePos() {
    return m_mousePos;
}
inline SDL_Renderer* game::getRenderer() {
    return m_renderer;
}

int game::pushDrawCallback(const IDrawable::RenderCallback& callback) {
    m_renderCallbacks.push_back(callback);
    return game::SUCCESS;
}

int game::pushDrawable(const IDrawable& drawable) {
    
    return game::SUCCESS;
}   