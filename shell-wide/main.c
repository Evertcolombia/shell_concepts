#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
    char *getLine;
    char **tokens;
    pid_t child;
    int  status;

	while (1)
	{
		write(1, "Mameme_el_bolo_chulitos$ ", 25);
		getLine = get_line();
        tokens = splitString(getLine);
        printCommand(tokens);
	}
    free(tokens);
	free(getLine);
	return (0);
}
