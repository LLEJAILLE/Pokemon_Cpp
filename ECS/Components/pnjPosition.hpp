/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** pnjPos
*/

#pragma once
#include "interface.hpp"

namespace rtype::ECS::Ecs3D {
    class PnjPosComponent : public IComponent {
        public:
            std::string id;
            Vector2 position;

            std::string getName() const override { return id; }


            // Constructor
            PnjPosComponent(Vector2 initialPosition, std::string id)
                : position(initialPosition), id(id) {}
    };
}