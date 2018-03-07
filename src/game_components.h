typedef struct Player {
    char playerNum;
    char *name; // Use malloc, then assign the pointer it returns to name
    struct territory* territories;
    struct region* continents[5];
} Player;

typedef struct region {
    struct territory* territories;
} Region;

typedef struct territory {
    char *name;
    struct player* controlledBy;
    int troopCount;
    struct territory* canReach[7];
    struct region* continent;
} Territory;

typedef struct game {
	char numberOfPlayers;
	int somethingElse;
} Game;
