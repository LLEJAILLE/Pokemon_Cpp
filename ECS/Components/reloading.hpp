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
            class ReloadingComponent : public IComponent {
                public:
                    std::string id;
                    float time;
                    bool shouldShoot = true;
                    bool finished = false;

                    // Constructor
                    ReloadingComponent(std::string id, float time)
                        : id(id), time(time) {}

                    std::string getName() const override { return id; }
            };
    }