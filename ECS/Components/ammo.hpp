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
            class AmmoComponent : public IComponent {
                public:
                    std::string id;
                    int nb_ammo;

                    // Constructor
                    AmmoComponent(std::string id, int nb_ammo)
                        : id(id), nb_ammo(nb_ammo) {}

                    std::string getName() const override { return id; }
            };
    }