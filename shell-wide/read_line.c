#include "shell.h"

char *get_line(void)
{
        char *new_line;
        size_t size = 1024;

        new_line = malloc(size * sizeof(char));
        if (new_line == NULL)
                return (NULL);
        getline(&new_line, &size, stdin);

        return new_line;
}
