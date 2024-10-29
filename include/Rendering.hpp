#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <functional>

namespace game
{
    class IDrawable {
    public:
        using RenderCallback = std::function<int()>;

        virtual int draw() const = 0;
    };
    class IRenderable {
    public:
        using RenderCallback = std::function<int(SDL_Point)>;

        virtual int render(SDL_Point pos) const = 0;
    };
} // game
#endif // DRAWABLE_OBJECT_H
