#include "../include/DrawableObject.hpp"
#include "../include/game.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

game::DrawInfo::DrawInfo(const SDL_Rect& dimesions, const SDL_Texture* texture) {
    m_dimensions = dimesions;
    m_type = game::DrawType::TEXTURE;
    m_texture = texture;
}
game::DrawInfo::DrawInfo(const SDL_Rect& dimesions, const SDL_Color& color) {
    m_dimensions = dimesions;
    m_type = game::DrawType::COLOR;
    m_color = color;
}

const SDL_Rect& game::DrawInfo::getDimensions() const {
    return m_dimensions;
}
const game::DrawType& game::DrawInfo::getType() const {
    return m_type;
}
const SDL_Texture* game::DrawInfo::getTexture() const {
    if (m_type != DrawType::TEXTURE)
        game::panic();
    return m_texture;
}
const SDL_Color& game::DrawInfo::getColor() const {
    return m_color;
}
