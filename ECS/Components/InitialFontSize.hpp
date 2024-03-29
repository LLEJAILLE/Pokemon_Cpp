/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** postion
*/

#pragma once
#include "interface.hpp"
#include "position2d.hpp"

    namespace ECS {
            class InitialFontSize : public IComponent {
                public:
                    std::string id;
                    float initial_size;

                    // Constructor
                    InitialFontSize(std::string id, float initial_size)
                        : id(id), initial_size(initial_size) {}

                    std::string getName() const override { return id; }
            };            
    }