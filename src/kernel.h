/*
 * Print an empty map. initscr() must have been called before this function
 * is called.
 */
void printEmptyMap();

/*
 * Print a message to the console. Max length = 159 characters.
 * The array passed MUST have a length <= 160 (including \0)
 * Character indices run from 0 - 158.
 */
void printMessage(char**);

/*
 * Prompt user for input. Method receives a pointer to a string.
 * Returns a string of the user's response.
 */
char* promptStr(char**, int);

/*
 * Prompt user for input. Method receives a pointer to a string.
 * Returns a pointer to an integer containing the user's response.
 */
int promptInt(char**);
