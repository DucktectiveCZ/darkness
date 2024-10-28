#ifndef SPRITE_H
#define SPRITE_H
#include "Font.hpp"
#include "Rendering.hpp"
#include "../include/Graphics.hpp"
#include "texture.hpp"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace game
{
    class Sprite : public IDrawable {
    public:
        Sprite(const Texture& texture, const Coordinate& x, const Coordinate& y);
        inline ~Sprite() = default;

        const SDL_Point& getPosition() const;
        Sprite& setPosition(const SDL_Point& position);
        const Texture& getTexture() const;
        Sprite& setTexture(const Texture& texture);
        const Font& getFont() const;
        Sprite& setFont(const Font& font);

        int render() const override;
    private:
        SDL_Point m_position;
        Texture m_texture;
    };
} // game
#endif // SPRITE_H