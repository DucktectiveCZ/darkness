#include "../include/texture.hpp"
#include "../include/game.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <string>

// ctor
game::Texture::Texture(std::string path)
{
    auto surf = IMG_Load(path.c_str());
    m_texture = SDL_CreateTextureFromSurface(game::getRenderer(), surf);
    s_textureReferences[m_texture]++;
    SDL_FreeSurface(surf);
}
// Copy
game::Texture::Texture(const Texture& other) {
    m_dimensions = other.m_dimensions;
    m_rotation = other.m_rotation;
    m_texture = other.m_texture;
    s_textureReferences[m_texture]++;
}
// Move
game::Texture::Texture(Texture&& other) noexcept {
    m_dimensions = other.m_dimensions;
    m_rotation = other.m_rotation;
    m_texture = other.m_texture;
    other.m_texture = nullptr;
}
// dtor
game::Texture::~Texture() {
    s_textureReferences[m_texture]--;
    if (s_textureReferences[m_texture] == 0) {
        SDL_DestroyTexture(m_texture);
    }
}
const SDL_Rect& game::Texture::getDimensions() const {
    return m_dimensions;
}
game::Texture& game::Texture::setDimensions(const SDL_Rect& val) {
    m_dimensions = val;
    return *this;
}
SDL_Texture* game::Texture::getTexture() const {
    return m_texture;
}
const float& game::Texture::getRotation() const {
    return m_rotation;
}
game::Texture& game::Texture::setRotation(const float& rotation) {
    m_rotation = rotation;
    return *this;
}

size_t game::Texture::getTxtRefs() const {
    return s_textureReferences[m_texture];
}

game::Texture& game::Texture::operator=(const Texture& other) {
    if (this != &other) { // Check for self-assignment
        m_dimensions = other.m_dimensions;
        m_rotation = other.m_rotation;
        m_texture = other.m_texture;
        s_textureReferences[m_texture]++;
    }
    return *this;
}

int game::Texture::render(SDL_Point pos) const {
    SDL_RenderCopyEx(game::getRenderer(), m_texture, NULL, &m_dimensions, m_rotation, &pos, SDL_FLIP_NONE);
    return game::SUCCESS;
}