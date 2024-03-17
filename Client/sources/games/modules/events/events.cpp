#include "events.hpp"

namespace rtype::modules {
    void Events::printEvent(const std::string &action, float deltatime) {
        int key = 0;
        std::string formatString = action;
        formatString = formatString.substr(formatString.find("\"") + 1, formatString.rfind("\"") - formatString.find("\"") - 1);
        bool writtingFinished = false;
        bool isSecondLine = false;

        std::string firstLine = formatString.substr(0, 105);
        std::string secondLine;

        if (formatString.length() > 105) {
            isSecondLine = true;
            size_t lastSpace = firstLine.find_last_of(' ');
            firstLine = firstLine.substr(0, lastSpace);

            secondLine = formatString.substr(lastSpace + 1);
        }

        while (key != 32) {
            if (!writtingFinished) {
                for (size_t i = 0; i < firstLine.length(); ++i) {                    
                    std::string partialString = firstLine.substr(0, i + 1); // Sous-chaîne de la chaîne complète

                    BeginDrawing();
                    DrawTextureEx(_dialogBox, { 0, static_cast<float>(GetScreenHeight() - 160) }, 0, 1.023, WHITE);
                    DrawText(partialString.c_str(), 50, GetScreenHeight() - 120, 32, BLACK);
                    EndDrawing();

                    std::this_thread::sleep_for(std::chrono::milliseconds(15));
                }

                for (size_t i = 0; i < secondLine.length(); ++i) {
                    std::string partialString = secondLine.substr(0, i + 1); // Sous-chaîne de la chaîne complète

                    BeginDrawing();
                    DrawTextureEx(_dialogBox, { 0, static_cast<float>(GetScreenHeight() - 160) }, 0, 1.023, WHITE);
                    DrawText(firstLine.c_str(), 50, GetScreenHeight() - 120, 32, BLACK);
                    DrawText(partialString.c_str(), 50, GetScreenHeight() - 90, 32, BLACK);
                    EndDrawing();

                    std::this_thread::sleep_for(std::chrono::milliseconds(15));
                }

                writtingFinished = true;
            }

            BeginDrawing();
            DrawTextureEx(_dialogBox, { 0, static_cast<float>(GetScreenHeight() - 160) }, 0, 1.023, WHITE);

            DrawText(firstLine.c_str(), 50, GetScreenHeight() - 120, 32, BLACK);

            if (isSecondLine) {
                DrawText(secondLine.c_str(), 50, GetScreenHeight() - 90, 32, BLACK);
            }
           
            EndDrawing();

            key = GetKeyPressed();
        }
    }

    void Events::moveEvent(const std::string &action, float deltatime) {
        std::cout << action << std::endl;
    }
}