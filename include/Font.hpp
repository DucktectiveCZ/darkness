#ifndef FONT_HPP
#define FONT_HPP
#include "Rendering.hpp"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>
#include <string>
namespace game
{
    class Font : IRenderable {
    public:
        Font(std::string path, int size);

        int getSize() const;
        const Font& setSize(int size);

        int render(SDL_Point pos) const override;
    private:
        TTF_Font* m_font;
    };
} // game
#endif // FONT_HPP