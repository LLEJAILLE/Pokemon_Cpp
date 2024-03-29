/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** velocity
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class VelocityComponent : public IComponent {
        public:
            float velocity;
            std::string id;

            // Constructor
            VelocityComponent(float initialSpeed, std::string id)
                : velocity(initialSpeed), id(id) {}

            VelocityComponent()
            {
                velocity = 0.3f;
                id = "default";
            }

            std::string getName() const override { return id; }
    };
}