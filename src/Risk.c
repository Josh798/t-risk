#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
//#include "game_components.h"
#include "kernel.h"
#define WIDTH 144
#define HEIGHT 43




int main() {
    setlocale(LC_ALL, "");
    initscr();
    raw();
    printEmptyMap();

    setupGame();

    getch();
    endwin();
    return 0;
}
