#include <stdlib.h>
#include <stdio.h>

int main(__attribute__((unsused)) int ac, char **av)
{
        int i = 0;

        while (*av++)
        {
                printf("%s\n", *av);
        }
        return (0);
}


