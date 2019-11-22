#include "shell.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
        char **enviroment = environ;


        printf("address of the enviroment: %p\n", (char *)enviroment);

        printf ("adress of the env: %p\n", (char *)env);

        return (0);
}
