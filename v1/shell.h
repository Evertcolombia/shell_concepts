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
#include <stdarg.h>
#include <stddef.h>

extern char **environ;
char *buffer;

/* structure for linked list elements. */
typedef struct history_s {
	char * data;
	int len;
	struct history_s *next;
} hstr_t;
/* structure for history control flow of the commands history linkd list*/
typedef struct hstr_list {
	int size;

	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	hstr_t *head;
	hstr_t *last_in;
	hstr_t *tail;
} List;
/* structure for linked list PATH elements. */
typedef struct path_s {
	char *pathname;
	int len;
	struct path_s *next;
} path_t;

/* structure for the built-in commands */
typedef struct cmd_s {
	char * cname;
	int (*func)(char *token, path_t *_path, List *_list);
} cmd_t;

/*prototypes for control de history linked list*/

void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, hstr_t *element, const void *data, int len);
int list_rem_next(List *list, hstr_t *element, void **data);
void print_history_safe(List *list, hstr_t *head);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)


/* prototypes for the pointer to functios control */
int (*search_in_optionals(char *cname))(char *cname, path_t *_path, List *_list);
int exit_helper(char *cname, path_t *_path, List __attribute__((unused)) *_list);
int history_helper(char *cname, path_t __attribute__((unused)) *path, List *_list);

/* prototypes for the signal */
void handleCtrlc(int i);

/* prototypes for the buffer line */
char *get_line(path_t *head, List *_list);
int validate_line(int len, char *buffer);

/* prototypes for process uses */
void fork_process(char *tokens[], char *buffer);
path_t *create_path_list();

/* prototypes for  strings uses  */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/* prototypes for the PATH linked lists */
path_t *add_node(path_t **head, char *pathname);
size_t print_listint_safe(path_t *head);
char *search_path(char *pathname, path_t *head);
size_t free_listint_safe(path_t **h);

/* prototypes for other helpes */
void *_calloc(unsigned int nmemb, unsigned int size);
char *_memset(char *s, char b, unsigned int n);

#endif /* SHELL_H */
