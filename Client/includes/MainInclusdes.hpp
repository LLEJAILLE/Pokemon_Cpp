/*
** EPITECH PROJECT, 2023
** RType
** File description:
** MainInclusdes
*/

#pragma once
    #include "./CommonIncludes.hpp"
    #include "../sources/games/soundManager/soundManager.hpp"


static const std::map<int, std::string> inputKeyBoardMap = {
    {KEY_APOSTROPHE, "\'"},
    {KEY_COMMA, ","},
    {KEY_MINUS, "-"},
    {KEY_PERIOD, "."},
    {KEY_SLASH, "/"},
    {KEY_ZERO, "0"},
    {KEY_ONE, "1"},
    {KEY_TWO, "2"},
    {KEY_THREE, "3"},
    {KEY_FOUR, "4"},
    {KEY_FIVE, "5"},
    {KEY_SIX, "6"},
    {KEY_SEVEN, "7"},
    {KEY_EIGHT, "8"},
    {KEY_NINE, "9"},
    {KEY_SEMICOLON, ";"},
    {KEY_EQUAL, "="},
    {KEY_A, "A"},
    {KEY_B, "B"},
    {KEY_C, "C"},
    {KEY_D, "D"},
    {KEY_E, "E"},
    {KEY_F, "F"},
    {KEY_G, "G"},
    {KEY_H, "H"},
    {KEY_I, "I"},
    {KEY_J, "J"},
    {KEY_K, "K"},
    {KEY_L, "L"},
    {KEY_M, "M"},
    {KEY_N, "N"},
    {KEY_O, "O"},
    {KEY_P, "P"},
    {KEY_Q, "Q"},
    {KEY_R, "R"},
    {KEY_S, "S"},
    {KEY_T, "T"},
    {KEY_U, "U"},
    {KEY_V, "V"},
    {KEY_W, "W"},
    {KEY_X, "X"},
    {KEY_Y, "Y"},
    {KEY_Z, "Z"},
    {KEY_LEFT_BRACKET, "["},
    {KEY_BACKSLASH, "\\"},
    {KEY_RIGHT_BRACKET, "]"},
    {KEY_GRAVE, "`"},
    {KEY_SPACE, "Space"},
    {KEY_ESCAPE, "Esc"},
    {KEY_ENTER, "Enter"},
    {KEY_TAB, "Tab"},
    {KEY_BACKSPACE, "Backspace"},
    {KEY_INSERT, "Ins"},
    {KEY_DELETE, "Del"},
    {KEY_RIGHT, "Cursor right"},
    {KEY_LEFT, "Cursor left"},
    {KEY_DOWN, "Cursor down"},
    {KEY_UP, "Cursor up"},
    {KEY_PAGE_UP, "Page up"},
    {KEY_PAGE_DOWN, "Page down"},
    {KEY_HOME, "Home"},
    {KEY_END, "End"},
    {KEY_CAPS_LOCK, "Caps lock"},
    {KEY_SCROLL_LOCK, "Scroll down"},
    {KEY_NUM_LOCK, "Num lock"},
    {KEY_PRINT_SCREEN, "Print screen"},
    {KEY_PAUSE, "Pause"},
    {KEY_F1, "F1"},
    {KEY_F2, "F2"},
    {KEY_F3, "F3"},
    {KEY_F4, "F4"},
    {KEY_F5, "F5"},
    {KEY_F6, "F6"},
    {KEY_F7, "F7"},
    {KEY_F8, "F8"},
    {KEY_F9, "F9"},
    {KEY_F10, "F10"},
    {KEY_F11, "F11"},
    {KEY_F12, "F12"},
    {KEY_LEFT_SHIFT, "Shift left"},
    {KEY_LEFT_CONTROL, "Control left"},
    {KEY_LEFT_ALT, "Alt left"},
    {KEY_LEFT_SUPER, "Super left"},
    {KEY_RIGHT_SHIFT, "Shift right"},
    {KEY_RIGHT_CONTROL, "Control right"},
    {KEY_RIGHT_ALT, "Alt right"},
    {KEY_RIGHT_SUPER, "Super right"},
    {KEY_KB_MENU, "KB menu"},
    {KEY_KP_0, "KEYpad 0"},
    {KEY_KP_1, "KEYpad 1"},
    {KEY_KP_2, "KEYpad 2"},
    {KEY_KP_3, "KEYpad 3"},
    {KEY_KP_4, "KEYpad 4"},
    {KEY_KP_5, "KEYpad 5"},
    {KEY_KP_6, "KEYpad 6"},
    {KEY_KP_7, "KEYpad 7"},
    {KEY_KP_8, "KEYpad 8"},
    {KEY_KP_9, "KEYpad 9"},
    {KEY_KP_DECIMAL, "KEYpad ."},
    {KEY_KP_DIVIDE, "KEYpad /"},
    {KEY_KP_MULTIPLY, "KEYpad *"},
    {KEY_KP_SUBTRACT, "KEYpad -"},
    {KEY_KP_ADD, "+"},
    {KEY_KP_ENTER, "Enter"},
    {KEY_KP_EQUAL, "="},
    {KEY_BACK, "back button"},
    {KEY_MENU, "menu button"},
    {KEY_VOLUME_UP, "volume up button"},
    {KEY_VOLUME_DOWN, "volume down button"},
    {MOUSE_BUTTON_LEFT, "Left click"},
    {MOUSE_BUTTON_RIGHT, "Right click"},
    {MOUSE_BUTTON_MIDDLE, "Middle click"},
    {MOUSE_BUTTON_SIDE, "Side click"},
    {MOUSE_BUTTON_EXTRA, "Extra click"}

};