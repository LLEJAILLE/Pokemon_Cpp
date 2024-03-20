/*
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_
    #include "../../../../includes/MainInclusdes.hpp"
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
            static void openMenu(bool &waitBeforeOpenMenu, bool &_IsMoving, Texture2D &_menu, Texture2D &_cursor, Vector2 &_cursorPos);            
    };
}

#endif /* !MENU_HPP_ */
