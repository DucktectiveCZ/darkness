#ifndef ENTITY_H
#define ENTITY_H
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <cstddef>
#include <string>
#include <sys/stat.h>
#include <unordered_map>

namespace game
{
    /// @brief A `SDL_Texture*` wrapper class
    class Texture {
    public:
        /// @brief Load a texture from a file
        /// @param path is the path to the file 
        Texture(std::string path);
        ~Texture();
        Texture(const Texture& other); // Copy
        inline Texture(Texture&& other) noexcept = default; // Move

        /// @brief Gets the texture's dimensions (width & height)
        const SDL_Rect& getDimensions() const;
        /// @brief Sets the texture's dimensions (width & height)
        /// @returns a reference to @this
        Texture& setDimensions(const SDL_Rect& value);
        /// @brief Gets the SDL_Texture*a
        /// @returns the SDL_Texture*s
        SDL_Texture* getTexture() const;
        /// @brief Gets the rotation
        /// @returns the rotation
        const float& getRotation() const;
        /// @brief Sets the rotation
        /// @returns a reference to @this
        game::Texture& setRotation(const float& value);

        Texture& operator=(const Texture& other); // Assign
        
        // debug
        size_t getTxtRefs() const;
    private:
        SDL_Rect m_dimensions;
        SDL_Texture* m_texture;
        float m_rotation = 0.0f;
        static std::unordered_map<SDL_Texture*, size_t> s_textureReferences; // counts the references to the SDL_Texture pointers
    };
} // game

#endif // ENTITY_H