/*
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_stdinc.h>
#include <functional>
#include <unordered_map>
namespace game
{
    using WindowEventHandler = std::function<int(const SDL_Event&)>;
    std::unordered_map<Uint32, WindowEventHandler> windowEvents = {
        { SDL_QUIT, quit }
    };
    int quit(const SDL_Event& e) {

        return 0;
    }
} // game
*/