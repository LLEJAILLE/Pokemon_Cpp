/*
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
    #include "../textures/textures.hpp"
    #include <filesystem>

namespace modules {
    enum MenuState {
        POKEMON,
        ITEM,
        PLAYER,
        SAVE,
        OPTION,
        EXIT
    };

    class Menu {
        Menu() = delete;
        ~Menu() = delete;


        public:
            static void openMenu(bool &waitBeforeOpenMenu, bool &_IsMoving, Texture2D &_menu, Texture2D &_cursor, Vector2 &_cursorPos, ECS::IEntity& player, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventsCol, std::string &_stateMoving, Rectangle &frameRec);
            static void draw(Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventsCol, ECS::IEntity &_myPlayer, std::string &_stateMoving, Rectangle &frameRec);
    };
}

#endif /* !MENU_HPP_ */
