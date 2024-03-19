/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** components
*/

#pragma once
#include "../common.hpp"

namespace ECS::Ecs3D {
    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual std::string getName() const = 0;
    };
}