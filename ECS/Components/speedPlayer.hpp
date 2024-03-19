/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** postion
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class SpeedPlayer : public IComponent {
        public:
            std::string id;
            float speed;

            // Constructor
            SpeedPlayer(std::string id, float speed)
                : id(id), speed(speed) {}

            std::string getName() const override { return id; }
    };
}