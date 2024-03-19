/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** buttonmenu
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class FloatRotation : public IComponent {
        public:
            float rotation;
            std::string id;

            // Constructor
            FloatRotation(float rotation, std::string id) {
                this->rotation = rotation;
                this->id = id;
            }

            std::string getName() const override { return id; }
    };
}