#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "game_components.h"
#include "kernel.h"

#include <string.h>
#include <errno.h>

void setupGame() {
	Game *game = getGame();
	setupPlayers(game);
	initializeTerritories(game);
	int i;
	for (i = 0; i < 42; i++) {
		refreshTroopCount(*(game->territories + i));
	}
	initialTroopPlacement(game);
	printTerritoryCodes(game);
}

void setupPlayers(Game* game) {
	int numberOfPlayers = promptInt(
			"Welcome to t-risk! How many players are playing (3 - 6)? ");
	while (numberOfPlayers < 3 || numberOfPlayers > 6) {
		numberOfPlayers =
				promptInt(
						"Error: the number of players must be between 3 and 6. How many players are playing? ");
	}
	game->numberOfPlayers = numberOfPlayers;
	game->players = (Player*) malloc((numberOfPlayers + 1) * (sizeof(Game)));
	char symbols[6] = {'@', '#', '$', '%', '&', '*'};
	// Player 0 shall refer to "nobody"
	game->players->name = "Nobody";
	game->players->symbol = ' ';
	game->players->playerNum = 0;
	int i;
	for (i = 1; i < numberOfPlayers + 1; i++) {
		char* prompt = (char*) malloc(28);
		sprintf(prompt, "Enter a name for player %d: ", i);
		(game->players + i)->name = promptStr(prompt, 12);
		(game->players + i)->playerNum = i + 1;
		(game->players + i)->symbol = symbols[i];
	}
}

void initializeTerritories(Game* game) {
	game->territories = (Territory**) malloc(42 * (sizeof(Territory*)));
	FILE* territoriesFile = fopen("../res/territories.csv", "r");
	char* line = (char*) malloc(28);
	int i = 0;
	while (fscanf(territoriesFile, "%[^\n]s", line) != EOF) {
		char* msg = (char*) malloc(15);
		char* id = (char*) malloc(3);
		char* name = (char*) malloc(20);
		char* ycoord = (char*) malloc(4);
		char* xcoord = (char*) malloc(4);
		char* code = (char*) malloc(3);
		parseElement(line, code,
				parseElement(line, xcoord,
						parseElement(line, ycoord,
								parseElement(line, name,
										parseElement(line, id, 0))))); // Lol YIKES
		Territory* t = (Territory*) malloc(sizeof(Territory));
		t->name = name;
		t->id = atoi(id);
		t->xcoord = atoi(xcoord);
		t->ycoord = atoi(ycoord);
		t->troopCount = 0;
		t->code = code;
		t->controlledBy = game->players; // Sets the controlling player to "Nobody"
		*(game->territories + i) = t;
		printMessage(msg);
		fgetc(territoriesFile); // Read in the delimiting character \n
		i++;
	}
	fclose(territoriesFile);
}

int parseElement(char* src, char* dest, int offset) {
	char c = *(src + offset);
	int i = offset + 1;
	int j = 0;
	while (c != ',' && c != '\n') {
		*(dest + j) = c;
		c = *(src + i);
		i++;
		j++;
	}
	*(dest + j) = '\0';
	return i;
}

void initialTroopPlacement(Game* game) {
	int initialTroopCount = 35 - 5 * (game->numberOfPlayers - 3);

}

void printTerritoryCodes(Game* game) {
	int i;
	for (i = 0; i < 42; i++) {
		mvaddstr((*(game->territories + i))->ycoord + 1,
				(*(game->territories + i))->xcoord,
				(*(game->territories + i))->code);
	}
}
