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
	int numberOfPlayers = setupPlayers();
	Game *game = getGame();
	game->numberOfPlayers = numberOfPlayers;
	game->players = (Player*) malloc(numberOfPlayers * (sizeof(Game)));
	nameAndNumberPlayers(game->players, game->numberOfPlayers);
	initializeTerritories();
	Territory* t = *(game->territories);
	updateTroopCount(t, 0);
}

int setupPlayers() {
	int returnValue = promptInt("Welcome to t-risk! How many players are playing (2 - 6)? ");
	while (returnValue < 2 || returnValue > 6) {
		returnValue = promptInt("Error: the number of players must be between 2 and 6. How many players are playing? ");
	}
	return returnValue;
}

void nameAndNumberPlayers(Player* players, int numberOfPlayers) {
	int i;
	for (i = 0; i < numberOfPlayers; i++) {
		char* prompt = (char*) malloc(28);
		sprintf(prompt, "Enter a name for player %d: ", i + 1);
		(players + i)->name = promptStr(prompt, 12);
		(players + i)->playerNum = i+1;
	}
}

void initializeTerritories() {
	Game* game = getGame();
	game->territories = (Territory**) malloc(42 * (sizeof(Territory*)));
	FILE* territoriesFile = fopen("../res/territories.csv", "r");
	char* line = (char*) malloc(28);
	int i = 0;
	while(fscanf(territoriesFile, "%[^\n]s", line) != EOF) {
		char* msg = (char*) malloc(15);
		char* id = (char*) malloc(3);
		char* name = (char*) malloc(20);
		char* ycoord = (char*) malloc(4);
		char* xcoord = (char*) malloc(4);
		parseElement(line, xcoord, parseElement(line, ycoord, parseElement(line, name, parseElement(line, id, 0)))); // Lol YIKES
		Territory* t = (Territory*) malloc(sizeof(Territory));
		t->name = name;
		t->id = atoi(id);
		t->xcoord = atoi(xcoord);
		t->ycoord = atoi(ycoord);
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

