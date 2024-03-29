/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** cubemodel
*/

#pragma once
#include "interface.hpp"

namespace ECS {
    class CubeModelComponent : public IComponent {
        public:
            Model model;
            std::string id;

            // Constructor
            CubeModelComponent(Model model, std::string id)
                : model(model), id(id) {}

            // Setters
            void setModel(Model newModel) {
                model = newModel;
            }

            // Infos
            void printModel() {
                std::cout << "Id: " << id.c_str() << std::endl;
            }

            std::string getName() const override { return id; }
    };
}