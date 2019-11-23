#ifndef SHELL_H
#define SHELL_H

/*Allowed Libraries*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char **splitString(char *line);
char *get_line(void);
void printCommand(char **tokens);
char *get_env(const char *path_name);
char **splitStringPath(char *arguments, char **argvs);
char *str_concat(char *s1, char *s2);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif/*SHELL_H*/