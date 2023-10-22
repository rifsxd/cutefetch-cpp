#include <iostream>
#include "colors.h"

#define CHARACTER ""

void display_colorpalette() {
    const char *colors[8] = {
        BLACK, RED, GREEN,
        YELLOW, BLUE, MAGENTA,
        CYAN, WHITE
    };

    for (int i = 0; i < 8; i++)
        std::cout << colors[i] << CHARACTER << " ";

    std::cout << RESET << std::endl;
}