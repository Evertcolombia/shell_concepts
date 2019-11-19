#include "shell.h"

void printCommand(char **tokens)
{
    pid_t child;
    int status;

    child = fork();

    if (child == -1)
        perror("error");

    if (child == 0)
        execve(tokens[0], tokens, NULL); /*execute program with the entire path*/
    else
        waitpid(-1, &status, 0); /*wait to end chil proccess*/
}