/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** postion
*/

#pragma once
#include "interface.hpp"

    namespace ECS {
            class Rectangle2d : public IComponent {
                public:
                    std::string id;
                    Rectangle rec;

                    Rectangle2d(std::string id, Rectangle rectangle) : id(id), rec(rectangle) {};
                    Rectangle2d() {
                        this->id = "default";
                        this->rec = {0, 0, 0, 0};
                    };

                    std::string getName() const override { return id; }

            };
    }