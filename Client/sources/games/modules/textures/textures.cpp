#include "textures.hpp"

void rtype::modules::Textures::updateTexture(float speed, float deltatime, bool isMoving, int& currentFrame, int& framesCounter, Rectangle& frameRec, float frameWidth, float frameHeight)
{
    if (!isMoving) {
        currentFrame = 0;
        frameRec.x = frameWidth * currentFrame;
        frameRec.y = frameHeight;
        return;
    }

    framesCounter++;
    if (framesCounter > 40) {
        currentFrame++;
        if (currentFrame >= 4) {
            currentFrame = 0;
        }
        framesCounter = 0;
    }

    frameRec.x = frameWidth * currentFrame;
    frameRec.y = frameHeight;
}