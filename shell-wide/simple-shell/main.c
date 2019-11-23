#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
    const char *path_name = "PATH";
    char *path;
    char *getLine;
    char **tokens;
    pid_t child;
    int  status;
	while (1)
	{
		write(1, "Mameme_el_bolo_chulitos$ ", 25);
		getLine = get_line();
        /*verification for getline for eof or -1 */
        /*get path from enviroment*/
        path = get_env(path_name);
        printf()
        tokens = splitString(getLine);
        printCommand(tokens);
	}
    free(tokens);
	free(getLine);
	return (0);
}
