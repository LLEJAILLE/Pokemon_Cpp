/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** velocity
*/

#pragma once
#include "interface.hpp"

namespace ECS::Ecs3D {
    class VelocityGravityComponent : public IComponent {
        public:
            float speed;
            std::string id;

            // Constructor
            VelocityGravityComponent(float initialSpeed, std::string id)
                : speed(initialSpeed), id(id) {}

            VelocityGravityComponent()
            {
                speed = 0.0f;
                id = "default";
            }

            std::string getName() const override { return id; }
    };
}