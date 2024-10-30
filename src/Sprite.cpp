
#include "../include/Sprite.hpp"

namespace game
{
    Sprite::Sprite(const Texture& texture, const Coordinate& x, const Coordinate& y)
        : m_texture(texture)
    {
        m_position.x = x;
        m_position.y = y;
    }

    const SDL_Point& Sprite::getPosition() const
    {
        return m_position;
    }

    Sprite& Sprite::setPosition(const SDL_Point& position)
    {
        m_position = position;
        return *this;
    }

    const Texture& Sprite::getTexture() const
    {
        return m_texture;
    }

    Sprite& Sprite::setTexture(const Texture& texture)
    {
        m_texture = texture;
        return *this;
    }

    int Sprite::draw() const
    {
        m_texture.render(m_position);
    }
}
