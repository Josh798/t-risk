struct player {
    char playerNum;
    struct territory* territories;
    struct region* continents[5];
};

struct region {
    struct territory* territories;
};

struct territory {
    char name[20];
    struct player* controlledBy;
    int troopCount;
    struct territory* canReach[7];
    struct region* continent;
};
