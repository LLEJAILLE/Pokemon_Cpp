#include "textures.hpp"

void modules::Textures::updateTexture(float speed, float deltaTime, bool isMoving, int& currentFrame, int& framesCounter, Rectangle& frameRec, float frameWidth, float frameHeight)
{
    if (!isMoving) {
        currentFrame = 0;
        frameRec.x = frameWidth * currentFrame;
        frameRec.y = frameHeight;
        return;
    }

    framesCounter += speed * deltaTime;
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

void modules::Textures::drawSpritePlayer(ECS::IEntity& myPlayer, std::string& stateMoving, Rectangle& frameRec)
{
    if (stateMoving == "right") {
        DrawTextureRec(myPlayer.getComponent<ECS::TextureRight>()->texture, frameRec, myPlayer.getComponent<ECS::PositionComponent2d>()->position, WHITE);
    } else if (stateMoving == "left") {
        DrawTextureRec(myPlayer.getComponent<ECS::TextureLeft>()->texture, frameRec, myPlayer.getComponent<ECS::PositionComponent2d>()->position, WHITE);
    } else if (stateMoving == "up") {
        DrawTextureRec(myPlayer.getComponent<ECS::TextureUp>()->texture, frameRec, myPlayer.getComponent<ECS::PositionComponent2d>()->position, WHITE);
    } else if (stateMoving == "down") {
        DrawTextureRec(myPlayer.getComponent<ECS::TextureDown>()->texture, frameRec, myPlayer.getComponent<ECS::PositionComponent2d>()->position, WHITE);
    }
}