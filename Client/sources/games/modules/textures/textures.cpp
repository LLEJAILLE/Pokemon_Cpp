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

void rtype::modules::Textures::drawSpritePlayer(rtype::ECS::Ecs3D::IEntity& myPlayer, std::string& stateMoving, Rectangle& frameRec)
{
    if (stateMoving == "right") {
        DrawTextureRec(myPlayer.getComponent<rtype::ECS::Ecs3D::TextureRight>()->texture, frameRec, myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    } else if (stateMoving == "left") {
        DrawTextureRec(myPlayer.getComponent<rtype::ECS::Ecs3D::TextureLeft>()->texture, frameRec, myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    } else if (stateMoving == "up") {
        DrawTextureRec(myPlayer.getComponent<rtype::ECS::Ecs3D::TextureUp>()->texture, frameRec, myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    } else if (stateMoving == "down") {
        DrawTextureRec(myPlayer.getComponent<rtype::ECS::Ecs3D::TextureDown>()->texture, frameRec, myPlayer.getComponent<rtype::ECS::Ecs3D::PositionComponent2d>()->position, WHITE);
    }
}