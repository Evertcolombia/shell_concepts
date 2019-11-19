#include "shell.h"

int main(void)
{
pid_t child;
char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
int status, i = 0;

	while (i < 5)
	{
		child = fork();
		if (child == -1)
		{
			perror("Error");
			break;
		}
		if (child == 0)
		{
			printf("Child: %d\n", (i + 1));
			sleep(2);
			execve(argv[0], argv, NULL);
		}
		else
		{
			waitpid(-1, &status, 0);
			printf("SOY TU PADRE\n");
		}
		i++;
	}
	return (0);
}
