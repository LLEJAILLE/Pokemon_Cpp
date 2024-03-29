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
            class FontSize : public IComponent {
                public:
                    std::string id;
                    float size;

                    // Constructor
                    FontSize(std::string id, float size)
                        : id(id), size(size) {}

                        std::string getName() const override { return id; }
            };
    }