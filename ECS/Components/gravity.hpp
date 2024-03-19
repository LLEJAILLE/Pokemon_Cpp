/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** gravity
*/

#pragma once
#include "hitboxgravity.hpp"
#include "position3d.hpp"
#include "velocity.hpp"

namespace ECS {
    class GravityComponent : public IComponent {
        public:
            float gravity;
            std::string id;
            bool enableGravity = true;

            // Constructor
            GravityComponent(float initialGravity, std::string id)
                : gravity(initialGravity), id(id) {}

            std::string getName() const override { return id; }
    };
}