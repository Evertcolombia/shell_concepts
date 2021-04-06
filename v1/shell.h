#ifndef SHELL_H
#define SHELL_H

/*Allowed Libraries*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

extern char **environ;
char *buffer;

void handleCtrlc(int i);
char *get_line(void);
char *line_buffer(char *buffer);
int validate_line(int len, char *buffer);
void fork_process(char *tokens[], char *buffer);
int _strlen(char *s);

#endif /* SHELL_H */
