/*
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
    #define TEXTURE_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include <filesystem>

namespace rtype::modules {
    class Textures {
        Textures() = default;
        ~Textures() = default;

        public:
            static void updateTexture(float speed, float deltatime, bool isMoving, int& currentFrame, int& framesCounter, Rectangle& frameRec, float frameWidth, float frameHeight);
    };
}

#endif /* !TEXTURE_HPP_ */