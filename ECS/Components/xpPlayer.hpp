/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** postion
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class XpPlayer : public IComponent {
        public:
            std::string id;
            float xp;

            // Constructor
            XpPlayer(std::string id, float xp)
                : id(id), xp(xp) {}

            std::string getName() const override { return id; }
    };
}