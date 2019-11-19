#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
	char **tokens;
	char *getLine;
	int i = 0;
	
	while (1)
	{
		write(1, "MiShellada$ ", 13);
		getLine = get_line();
        tokens =  splitString(getLine);
        
		while (tokens[i] != NULL)
        {
        	printf("%s\n", tokens[i]);
            i++;
        }
	}
	free(tokens);
	free(getLine);
	return (0);
}
