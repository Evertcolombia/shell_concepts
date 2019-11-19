#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
size_t size = 1024;
char *buff;
char **tokens;
int i = 0;
buff = malloc(size * sizeof(char));
	if (buff == NULL)
		return (-1);
	while (1)
	{
		write(1, "MiShellada$ ", 13);
		getline(&buff, &size, stdin);
                tokens =  lsh_split_line(buff);

                while (tokens[i] != NULL)
                {
                        printf("%s\n", tokens[i]);
                        i++;
                }

	}
	free(buff);
	return (0);
}
