#pragma once
#include "interface.hpp"

namespace rtype::ECS::Ecs3D {
    class EventClickComp : public IComponent {
        public:
            std::string id;
            std::string type;
            int numberEvent;
            std::string nameEvent;
            Vector2 position;
            Texture2D textureUp;
            Texture2D textureDown;
            Texture2D textureLeft;
            Texture2D textureRight;
            int actualNumberOfCommonSwitch;

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
            }

            std::string getName() const override { return id; }
    };
}