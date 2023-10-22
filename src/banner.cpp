#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "colors.h"

#define BANNER_MAX_ROWS 3
#define NUM_BANNERS 8

const char (*get_banner())[50] {
    static const char banners[NUM_BANNERS][BANNER_MAX_ROWS][50] = {
        {
            "(\\__/)   ",
            "(='.'=)   ",
            "(\")_(\") "
        },
        {
            "  /\\_/\\ ",
            " ( o.o )  ",
            "  > ^ <   "
        },
        {
            "  /\\__/  ",
            " ( o.o )  ",
            "  >(__)<  "
        },
        {
            "   /\\    ",
            "  /  \\   ",
            " /    \\  "
        },
        {
            "   \\ /   ",
            "    .     ",
            "   / \\   "
        },
        {
            "   _      ",
            " >(.)__   ",
            "   /\\/   "
        },
        {
            "   (\\ /) ",
            "  ( . . ) ",
            " c('')('')"
        },
        {
            "   \\ | / ",
            "    _|_   ",
            "   / | \\ "
        }
    };

    static bool initialized = false;
    if (!initialized) {
        std::srand(std::time(0));
        initialized = true;
    }

    int randomIndex = std::rand() % NUM_BANNERS;
    return banners[randomIndex];
}

const char *get_banner_row(int row) {
    if (row >= BANNER_MAX_ROWS) {
        std::cerr << "Invalid given row\n";
        std::exit(1);
    }

    const char (*banner)[50] = get_banner();
    return banner[row];
}

void prbannerrow(int r) {
    const char *str = get_banner_row(r);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '"') {
            std::cout << RED << str[i] << RESET;
        } else if (str[i] == '=') {
            std::cout << YELLOW << str[i] << RESET;
        } else if (str[i] == '(' || str[i] == ')') {
            std::cout << BLUE << str[i] << RESET;
        } else if (str[i] == '/') {
            std::cout << GREEN << str[i] << RESET;
        } else if (str[i] == '_') {
            std::cout << CYAN << str[i] << RESET;
        } else if (str[i] == '.') {
            std::cout << MAGENTA << str[i] << RESET;
        } else {
            std::cout << str[i];
        }
    }
}

