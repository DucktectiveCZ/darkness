#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace game
{
    /// An interface for objects that can be drawn without specifying their position.
    /// The `draw()` method is used to render the object on the screen.
    class IDrawable {
    public:
        /// Draws the object on the screen.
        /// @return The result of the drawing operation.
        virtual int draw() const = 0;
    };
    /// An interface for objects that can be rendered.
    /// The `render()` method is used to render the object on the screen.
    class IRenderable {
    public:
        /// The `render()` method is used to render the object on the screen.
        /// @param pos The position to render the object at.
        /// @return The result of the rendering operation.
        virtual int render(SDL_Point pos) const = 0;
    };
} // game
#endif // DRAWABLE_OBJECT_H
