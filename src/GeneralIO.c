#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "kernel.h"
#include <string.h>

void printMessage(char* msg) {
	mvaddstr(41, 0, msg);
	int i;
	// Clear anything that came after msg.
	for(i = strlen(msg); i < 159; i++) {
		mvaddstr(41, i, " ");
	}
	refresh();
}

char* promptStr(char* prompt, int length) {
	printMessage(prompt);
	move(41, strlen(prompt) + 1);
	char* str = (char *) malloc(length + 1);
	curs_set(1);
	getnstr(str, length);
	return str;
}

int promptInt(char* prompt) {
	printMessage(prompt);
	move(41, strlen(prompt) + 1);
	int input;
	curs_set(1);
	scanw("%d", &input);
	return input;
}

void refreshTroopCount(Territory* t) {
	int count = t->troopCount / 10;
	char bytesNeeded = 1;
	while (count > 0) {
		bytesNeeded++;
	}
	// bytesNeeded tells the number of bytes needed to print the number alone.
	// Note the expression "bytesNeeded + 2" The +2 is needed to account for \0 and the player symbol.
	char* countStr = (char*) malloc(bytesNeeded + 1);
	char* fullStr = (char*) malloc(bytesNeeded + 2);
	*fullStr = t->controlledBy->symbol;
	*(fullStr + 1) = '\0';
	sprintf(countStr, "%d", t->troopCount);
	strcat(fullStr, countStr);
	mvaddstr(t->ycoord, (t->xcoord - 1), fullStr);
	curs_set(0);
	refresh();
}


