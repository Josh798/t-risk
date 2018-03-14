#ifndef GAME_COMPONENTS_H
#define GAME_COMPONENTS_H

typedef struct player {
    int playerNum;
    char *name; // Use malloc, then assign the pointer it returns to name
    struct territory* territories;
    struct region* continents[5];
    char symbol;
} Player;

typedef struct region {
    struct territory* territories;
} Region;

typedef struct territory {
	// Note: the xcoord and ycoord tells where the troop count should be printed in the terminal.
	// Currently, this coordinate refers to the coordinate of the NUMBER of troops, NOT the player symbol.
	// This should be fixed later.
	int xcoord;
	int ycoord;
	int id;
    char *name;
    Player* controlledBy;
    int troopCount;
    struct territory* canReach[7];
    struct region* continent;
    char* code;
} Territory;

typedef struct game {
	int numberOfPlayers;
	Player* players;
	Territory** territories;
} Game;

#endif
