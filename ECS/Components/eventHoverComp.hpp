#pragma once
#include "interface.hpp"

namespace rtype::ECS::Ecs3D {
    class EventHoverComp : public IComponent {
        public:
            std::string id;
            std::string type;
            int numberEvent;
            std::string nameEvent;
            Vector2 position;
            int actualNumberOfCommonSwitch;

            std::map<int, std::vector<std::string>> events;

            EventHoverComp(std::string id, std::string type, int numberEvent, std::string nameEvent, Vector2 position, int numberOfCommonSwitch, std::map<int, std::vector<std::string>> events) {
                this->id = id;
                this->type = type;
                this->numberEvent = numberEvent;
                this->nameEvent = nameEvent;
                this->position = position;
                this->actualNumberOfCommonSwitch = numberOfCommonSwitch;
                this->events = events;
            }

            std::string getName() const override { return id; }
    };
}