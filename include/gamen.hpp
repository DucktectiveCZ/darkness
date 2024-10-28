/*
#ifndef GAME_H
#define GAME_H

#include "../include/DrawableObject.hpp"
#include <SDL2/SDL_rect.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

namespace game
{
    enum Error {
        SUCCESS = 0,
        UNKNOWN = 1,
        SDL_INIT,
        GAME_INIT,
        SDL_ERROR,
        ILLEGAL_GET,
    };
    void start();
    std::string getErrorName(Error error);
    std::string getErrorName(int error);
    void stop();
    int m_initsdl(); // Initialize SDL2
    int m_initGame(); // Initialize the game
    int m_start(); // Start the application
    void m_cleanup(int code = 0); // Cleanup SDL2
    int m_gameTick(); // Game loop
    void m_consoleLoop(); // Manages the console IO 
    int m_render(); // Rendering
    void m_clearScreen(); // Clean the window
    void panic(int errcode, std::string message); // Called on a fatal error
    void panic(int errcode);
    void panic();

    SDL_Point getMousePos();

    inline bool m_consoleLoopRunning; // Indicates whenever the console manager loop should run or not
    inline SDL_Point m_mousePos; // The mouse position buffer
    inline SDL_Window* m_window; // The main window
    inline SDL_Renderer* m_renderer; // The main window's renderer
    inline std::vector<game::DrawableObject> m_drawables; // Objects to be drawn
} // game

#endif // GAME_H
*/