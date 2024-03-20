#include "menu.hpp"

namespace modules {
    void goToPokedex() {
        std::cout << "go to pokedex" << std::endl;
    }

    void goToPokemon() {
        std::cout << "go to pokemon" << std::endl;
    }

    void goToItem() {
        std::cout << "go to item" << std::endl;
    }

    using MenuFunctionPtr = void (*)();
    MenuFunctionPtr menuFunctions[] = {
        goToPokedex,
        goToPokemon,
        goToItem
    };


    void Menu::openMenu(bool &waitBeforeOpenMenu, bool &_IsMoving, Texture2D &_menu, Texture2D &_cursor, Vector2 &_cursorPos)
    {
        int _stateMenu = 0;

        if (IsKeyPressed(KEY_X)) {
            waitBeforeOpenMenu = true;
        }

        if ((IsKeyPressed(KEY_X) && _IsMoving == false) || (_IsMoving == false && waitBeforeOpenMenu == true)) {
            int key = 0;

            while (key != KEY_X) {
                BeginDrawing();
                    DrawTextureEx(_menu, {1620, 0}, 0, 1.5, WHITE);
                    DrawText("POKéDEX", 1700, 50, 35, BLACK);
                    DrawText("POKéMON", 1700, 125, 35, BLACK);
                    DrawText("ITEM", 1700, 200, 35, BLACK);
                    DrawText("PLAYER", 1700, 275, 35, BLACK);
                    DrawText("SAVE", 1700, 350, 35, BLACK);
                    DrawText("OPTION", 1700, 425, 35, BLACK);
                    DrawText("EXIT", 1700, 500, 35, BLACK);

                    DrawTextureEx(_cursor, _cursorPos, 0, 0.5, WHITE);
                EndDrawing();
                

                if (key == KEY_DOWN) {
                    if (_cursorPos.y < 500) {
                        _cursorPos.y += 75;
                        _stateMenu++;
                    }
                } else if (key == KEY_UP) {
                    if (_cursorPos.y > 50) {
                        _cursorPos.y -= 75;
                        _stateMenu--;
                    }
                }

                if (key == 32 && menuFunctions[_stateMenu] != nullptr) {
                    menuFunctions[_stateMenu]();
                }

                key = GetKeyPressed();

            }

            waitBeforeOpenMenu = false;
            _cursorPos.y = 50;
        }
    }
}