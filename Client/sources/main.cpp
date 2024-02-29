/*
** EPITECH PROJECT, 2023
** RType
** File description:
** main
*/

#include "../includes/MainInclusdes.hpp"
#include "games/Game.hpp"

int main(void)
{
    Game game;

    game.detach();
    std::cout << "Game is detached" << std::endl;

    game.run();

    return 0;
}
