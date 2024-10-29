#ifndef GAME_H
#define GAME_H

#include "../include/Rendering.hpp"
#include <SDL2/SDL_rect.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

namespace game
{
    // Types
    enum Status {
        SUCCESS = 0,
        UNKNOWN = 1,
        SDL_INIT,
        GAME_INIT,
        SDL_ERROR,
        ILLEGAL_GET,
    };
    // Methods
    void start();
    std::string getErrorName(Status error);
    std::string getErrorName(int error);
    void stop();
    void panic(int errcode, std::string message); // Called on a fatal error
    void panic(int errcode);
    void panic();
    Status registerDrawable(IDrawable* drawable);
    Status unregisterDrawable(IDrawable* drawable);

    // Getters & Setters
    const SDL_Point& getMousePos();
    SDL_Renderer* getRenderer();

    // Private Methods
    int m_initsdl(); // Initialize SDL2
    int m_initGame(); // Initialize the game
    int m_start(); // Start the application
    void m_cleanup(int code = 0); // Cleanup SDL2
    int m_gameTick(); // Game loop
    int m_render(); // Rendering
    void m_clearScreen(); // Clean the window

    // Private Variables
    inline SDL_Point m_mousePos; // The mouse position buffer
    inline SDL_Window* m_window; // The main window
    inline SDL_Renderer* m_renderer; // The main window's renderer
    inline std::vector<IDrawable*> m_drawables; // IDrawable objects to draw
} // game

#endif // GAME_H