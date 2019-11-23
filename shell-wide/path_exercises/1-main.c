#include "shell.h"

int main (void)
{

    char *path;
    char **tokens;
    int i = 0;

    path  = get_env("PATH");
    tokens = splitString(path);

    while (tokens[i] != NULL)
    {
        printf("%s\n", tokens[i]);
        i++;
    }
    free(tokens);
    return (0);
}
