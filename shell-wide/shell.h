#ifndef SHELL_H
#define SHELL_H

/*Allowed Libraries*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char **splitString(char *line);
char *get_line(void);
void printCommand(char **tokens);

#endif/*SHELL_H*/
