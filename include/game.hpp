#ifndef GAME_H
#define GAME_H

#include "../include/Rendering.hpp"
#include <SDL2/SDL_rect.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

/// The `game` namespace contains the core functionality of the game application.
namespace game
{
    // Types

    /// Enumeration of possible status codes returned by the game engine.
    ///
    /// - `SUCCESS`: The operation completed successfully.
    /// - `UNKNOWN`: An unknown error occurred.
    /// - `SDL_INIT`: An error occurred during SDL initialization.
    /// - `GAME_INIT`: An error occurred during game initialization.
    /// - `SDL_ERROR`: An SDL-related error occurred.
    /// - `ILLEGAL_GET`: An illegal attempt was made to retrieve a value.
    enum Status {
        SUCCESS = 0,
        UNKNOWN = 1,
        SDL_INIT,
        GAME_INIT,
        SDL_ERROR,
        ILLEGAL_GET,
    };
    // Methods

    /// Starts the game application.
    ///
    /// This function initializes the game engine, starts the main game loop, and handles the application lifecycle.
    void start();
    /// Stops the game application.
    ///
    /// This function terminates the main game loop and performs any necessary cleanup before the application exits.
    void stop();
    /// Returns the string representation of the given Status code.
    ///
    /// @param error The Status code to get the name for.
    /// @return The string representation of the given Status code.
    std::string getStatusName(Status error);
    /// Returns the string representation of the given Status code.
    ///
    /// @param error The Status code to get the name for.
    /// @return The string representation of the given Status code.
    std::string getStatusName(int error);
    /// Logs a fatal error and terminates the application.
    ///
    /// This function should be called when a critical error occurs that prevents the application from continuing to run safely. It will log the error code and any provided message, then terminate the application.
    ///
    /// @param errcode The error code to log.
    /// @param message An optional message to provide more context about the error.
    void panic(int errcode, std::string message);
    /// Logs a fatal error and terminates the application.
    ///
    /// This function should be called when a critical error occurs that prevents the application from continuing to run safely. It will log the error code and any provided message, then terminate the application.
    ///
    /// @param errcode The error code to log.
    void panic(int errcode);
    void panic();
    /// Registers a drawable object with the game engine.
    ///
    /// This function adds the provided `IDrawable` object to the list of drawables that will be rendered each frame. The game engine will call the `draw()` method on each registered drawable during the rendering phase of the game loop.
    ///
    /// @param drawable The `IDrawable` object to register with the game engine.
    /// @return The `Status` of the registration operation. `SUCCESS` if the drawable was registered successfully, or an error code if the registration failed.
    Status registerDrawable(IDrawable* drawable);
    /// Unregisters a drawable object from the game engine.
    ///
    /// This function removes the provided `IDrawable` object from the list of drawables that will be rendered each frame. After this function is called, the game engine will no longer call the `draw()` method on the specified drawable.
    ///
    /// @param drawable The `IDrawable` object to unregister from the game engine.
    /// @return The `Status` of the unregistration operation. `SUCCESS` if the drawable was unregistered successfully, or an error code if the unregistration failed.
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