#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
    char *path;
    char *getLine;
    char **tokens;
    char **path_tokens;
    pid_t child;
    int  status;
    int i = 0;
	while (1)
	{
		write(1, "Mameme_el_bolo_chulitos$ ", 25);
		getLine = get_line();
        tokens = splitString(getLine);

        /*if (access(tokens[0], X_OK) == 0)
        {
            printCommand(tokens);
            free(tokens);
        }
        else
        {
            path = get_env("PATH");   
        }*/
        
        

        
        /*verification for getline for eof or -1 */
        /*get path from enviroment*/
        path = get_env("PATH");
        path_tokens = splitStringPath(path, tokens);
        while (path_tokens[i] != NULL)
        {
            /*if (access(path_tokens[i], X_OK) == 0)
            {
                printCommand(path_tokens);
                free(path_tokens);
            }
            else
                printf("nothing\n");*/
            printf("%s\n", path_tokens[i]);
            i++;
        }
	} 
	free(getLine);
	return (0);
}
