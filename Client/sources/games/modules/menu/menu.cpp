#include "menu.hpp"

namespace modules {
    void goToPokedex(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        std::cout << "go to pokedex" << std::endl;
    }

    void getMovesOfPokemon(ECS::IEntity& player, std::string movesStr) {
        std::vector<int> moves;
        std::string delimiter = ", ";
        size_t pos = 0;
        std::string token;

        while ((pos = movesStr.find(delimiter)) != std::string::npos) {
            token = movesStr.substr(0, pos);
            moves.push_back(std::stoi(token));
            movesStr.erase(0, pos + delimiter.length());
        }
        moves.push_back(std::stoi(movesStr));

        for (int i = 0; i < player.getComponent<ECS::MovePokemons>()->movesPokemons.size(); i++) {
            for (int j = 0; j < player.getComponent<ECS::MovePokemons>()->movesPokemons[i].size(); j++) {
                for (int k = 0; k < moves.size(); k++) {
                    if (std::stoi(player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["id"]) == moves[k]) {
                        std::cout << "      name: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["name"] << std::endl;
                        std::cout << "      type: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["type"] << std::endl;
                        std::cout << "      category: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["category"] << std::endl;
                        std::cout << "      power: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["power"] << std::endl;
                        std::cout << "      accuracy: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["accuracy"] << std::endl;
                        std::cout << "      pp: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["pp"] << std::endl;
                        std::cout << "      priority: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["priority"] << std::endl;
                        std::cout << "      effect: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["effect"] << std::endl;
                        std::cout << "      description: " << player.getComponent<ECS::MovePokemons>()->movesPokemons[i][j]["description"] << std::endl;

                        std::cout << std::endl;
                    }
                }
            }
        }
    }

    void goToPokemon(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        for (int i = 0; i < player.getComponent<ECS::InfosPlayer>()->playerPokemons.size(); i++) {
            for (int j = 0; j < player.getComponent<ECS::InfosPlayer>()->playerPokemons[i].size(); j++) {
                std::cout << "name: " << player.getComponent<ECS::InfosPlayer>()->playerPokemons[i][j]["name"] << std::endl;

                getMovesOfPokemon(player, player.getComponent<ECS::InfosPlayer>()->playerPokemons[i][j]["moves"]);
            }
        }
    }

    void goToItem(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        for (const auto &item : player.getComponent<ECS::InfosPlayer>()->_inventoryPlayer) {
            int idItem = item.first;
            int nbItem = item.second;

            auto it = std::find_if(player.getComponent<ECS::ItemsPlayer>()->items.begin(), player.getComponent<ECS::ItemsPlayer>()->items.end(), [idItem](const auto& itemVec) {
                return std::get<int>(itemVec[0]) == idItem;
            });

            if (it != player.getComponent<ECS::ItemsPlayer>()->items.end()) {
                const auto& itemInfo = *it;

                std::cout << std::get<std::string>(itemInfo[1]) << " ";
                std::cout << std::get<std::string>(itemInfo[2]) << " ";

                std::cout << "Quantity: " << nbItem << std::endl;   
            }
        }
    }

    void goToPlayerInfo(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        int keyCardPlayer = 0;
        std::string time = std::to_string(player.getComponent<ECS::InfosPlayer>()->hoursPlayed) + ":" +  std::to_string(player.getComponent<ECS::InfosPlayer>()->minutesPlayed);

        while (keyCardPlayer != KEY_X) {
            BeginDrawing();
                DrawRectangle(0, 0, 1920, 1080, WHITE);
                DrawText("NAME", 100, 50, 35, BLACK);
                DrawText(player.getComponent<ECS::InfosPlayer>()->name.c_str(), 355, 50, 35, BLACK);
                DrawText("MONEY ", 100, 125, 35, BLACK);
                DrawText(std::to_string(player.getComponent<ECS::InfosPlayer>()->pokeDollar).c_str(), 355, 125, 35, BLACK);
                DrawText("TIME", 100, 200, 35, BLACK);
                DrawText(time.c_str(), 355, 200, 35, BLACK);
            EndDrawing();

            keyCardPlayer = GetKeyPressed();
        }
        key = 88;
        reOpenMenu = true;
    }

    void goToSave(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        std::cout << "go to save" << std::endl;
    }

    void goToOption(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        std::cout << "go to option" << std::endl;
    }

    void goToExit(ECS::IEntity& player, int &key, bool &reOpenMenu) {
        std::cout << "go to exit" << std::endl;
        key = 88;
    }

    using MenuFunctionPtr = void (*)(ECS::IEntity& player, int& key, bool &reOpenMenu);
    MenuFunctionPtr menuFunctions[] = {
        goToPokedex,
        goToPokemon,
        goToItem,
        goToPlayerInfo,
        goToSave,
        goToOption,
        goToExit
    };


    void Menu::openMenu(bool &waitBeforeOpenMenu, bool &_IsMoving, Texture2D &_menu, Texture2D &_cursor, Vector2 &_cursorPos, ECS::IEntity& player, Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventsCol, std::string &_stateMoving, Rectangle &frameRec) {
        int _stateMenu = 0;

        if (IsKeyPressed(KEY_X)) {
            waitBeforeOpenMenu = true;
        }

        if ((IsKeyPressed(KEY_X) && _IsMoving == false) || (_IsMoving == false && waitBeforeOpenMenu == true)) {
            int key = 0;
            bool reOpenMenu = false;
            while (key != KEY_X) {
                BeginDrawing();
                    DrawTextureEx(_menu, {1620, 0}, 0, 1.5, WHITE);
                    DrawText("POKéDEX", 1700, 50, 35, BLACK);
                    DrawText("POKéMON", 1700, 125, 35, BLACK);
                    DrawText("ITEM", 1700, 200, 35, BLACK);
                    DrawText(player.getComponent<ECS::InfosPlayer>()->name.c_str(), 1700, 275, 35, BLACK);
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
                key = GetKeyPressed();

                if (key == 32 && menuFunctions[_stateMenu] != nullptr) {
                    menuFunctions[_stateMenu](player, key, reOpenMenu);
                }
            }

            draw(camera, _map, _eventsCol, player, _stateMoving, frameRec);

            if (reOpenMenu == true) {
                _stateMenu = 0;
                reOpenMenu = false;
                _cursorPos.y = 50;
                openMenu(waitBeforeOpenMenu, _IsMoving, _menu, _cursor, _cursorPos, player, camera, _map, _eventsCol, _stateMoving, frameRec);
            }


            waitBeforeOpenMenu = false;
            _cursorPos.y = 50;
        }
    }

    void Menu::draw(Camera2D &camera, std::map<int, std::shared_ptr<ECS::IEntity>> &_map, std::map<int, std::shared_ptr<ECS::IEntity>> &_eventsCol, ECS::IEntity &_myPlayer, std::string &_stateMoving, Rectangle &frameRec) {
        BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(WHITE);
        BeginMode2D(camera);
            for (int i = 0; i < _map.size(); i++) {
                DrawTexture(_map[i]->getComponent<ECS::Texture2d>()->texture, _map[i]->getComponent<ECS::PositionComponent2d>()->position.x, _map[i]->getComponent<ECS::PositionComponent2d>()->position.y, WHITE);
            }

            // draw pnj
            for (int i = 0; i < _eventsCol.size(); i++) {
                DrawTextureRec(_eventsCol[i]->getComponent<ECS::EventClickComp>()->actualTexture, {0, 0, 50, 50}, _eventsCol[i]->getComponent<ECS::EventClickComp>()->position, WHITE);
            }

            modules::Textures::drawSpritePlayer(_myPlayer, _stateMoving, frameRec);


        EndMode2D();

        EndDrawing();
    }

}