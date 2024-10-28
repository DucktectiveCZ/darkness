#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL2/SDL_rect.h>
namespace game
{
    using Point = SDL_Point;
    using Rectangle = SDL_Rect;
    using Dimension = SDL_Rect;
    using Color = SDL_Color;
    using Coordinate = long;

    /// @brief A base interface for all shape classes
    class Shape {
    public:
        /// @brief Gets the color of the shape
        /// @returns the color of the shape
        const Color& getColor() const;
        const Shape& setColor(const Color& color);
    private:
        Color m_color;
    };
    /// @brief A line shape
    class Line : public Shape {
    public:
        Line(Point x, Point y);
        
        const Point& getX() const;
        Line& setX(const Point& x);
        const Point& getY() const;
        Line& setY(const Point& y);
    private:
        Point m_x;
        Point m_y;
    };    
} // game
#endif // GRAPHICS_H