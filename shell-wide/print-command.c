#include "shell.h"

void printCommand(char **tokens)
{
    pid_t child;
    int status;

    child = fork();

    if (child == -1)
        perror("error");

    /*if (child == 0)
        execve(tokens[0], tokens, NULL);
    else
        waitpid(-1, &status, 0);*/
    child == 0 ? execve(tokens[0], tokens, NULL) :
        waitpid(-1, &status, 0);
}