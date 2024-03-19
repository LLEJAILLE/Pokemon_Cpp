#pragma once
#include "interface.hpp"

namespace ECS::Ecs3D {
    class EventClickComp : public IComponent {
        public:
            int numberEvent;
            std::string id;
            std::string type;
            std::string nameEvent;
            Vector2 position;
            Texture2D textureUp;
            Texture2D textureDown;
            Texture2D textureLeft;
            Texture2D textureRight;
            int actualNumberOfCommonSwitch;
            
            // actual texture
            Texture2D actualTexture;

            // update direction of the texture
            std::string stateMoving = "down";

            // usage to update the frame of the texture
            bool isMoving = false;
            float speed = 30.0f;
            int currentFrame = 0;
            int framesCounter = 0;
            float frameWidth = 50;
            float frameHeight = 50;
            Rectangle frameRec = { 0, 0, 50, 50 };

            bool isVisible = true;

            std::map<int, std::vector<std::string>> events;

            EventClickComp(std::string id, std::string type, int numberEvent, std::string nameEvent, Vector2 position, Texture2D textureUp, Texture2D textureDown, Texture2D textureLeft, Texture2D textureRight, int numberOfCommonSwitch, std::map<int, std::vector<std::string>> events) {
                this->id = id;
                this->type = type;
                this->numberEvent = numberEvent;
                this->nameEvent = nameEvent;
                this->position = position;
                this->textureUp = textureUp;
                this->textureDown = textureDown;
                this->textureLeft = textureLeft;
                this->textureRight = textureRight;
                this->actualNumberOfCommonSwitch = numberOfCommonSwitch;
                this->events = events;
                this->actualTexture = textureDown;
            }

            std::string getName() const override { return id; }
    };
}