#include "shell.h"
#include <stdio.h>

int main (void)
{
        char **enviroment;
        int i = 0;

        enviroment = environ;

        while (enviroment[i] != NULL)
        {
                printf("%s\n", enviroment[i]);
                i++;
        } return (0);
}
