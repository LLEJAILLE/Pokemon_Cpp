/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** pnjName
*/

#pragma once
#include "interface.hpp"

namespace ECS::Ecs3D {
    class PnjNameComponent : public IComponent {
        public:
            std::string id;
            std::string name;

            std::string getName() const override { return id; }


            // Constructor
            PnjNameComponent(std::string name, std::string id)
                : name(name), id(id) {}
    };
}