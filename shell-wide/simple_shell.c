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
buff = malloc(size * sizeof(char));
	if (buff == NULL)
		return (-1);
	while (1)
	{
		write(1, "MiShellada$ ", 13);
		getline(&buff, &size, stdin);
		printf("%s", buff);
	}
	free(buff);
	return (0);
}
