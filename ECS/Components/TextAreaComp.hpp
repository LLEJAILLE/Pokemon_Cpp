/*
** EPITECH PROJECT, 2023
** ecs_rType
** File description:
** postion
*/

#pragma once
#include "interface.hpp"

    namespace ECS {
            class TextAreaComp : public IComponent {
                public:
                    std::string id;
                    bool isFocus;
                    int nbChar;

                    TextAreaComp(std::string id, bool isFocus, int nbChar) : id(id), isFocus(isFocus), nbChar(nbChar) {};

                    std::string getName() const override { return id; }
            };
    }
