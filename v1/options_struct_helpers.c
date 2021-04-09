#include "shell.h"

int (*search_in_optionals(char *cname))(char *cname, path_t *_path, List *_list)
{
	int i = 0;

	cmd_t options[] = {
		{"history", history_helper},
		{"exit", exit_helper}
	};

	while (i < 2) {
		if (_strcmp(cname, options[i].cname) == 0)
			return (options[i].func);
		i++;
	}
	return (NULL);
}

int exit_helper(char *cname, path_t *_path, List  __attribute__((unused)) *_list)
{
	cname = cname;
	free_listint_safe(&_path);
	free(buffer);
	exit(1);
}

int history_helper(char *cname, path_t __attribute__((unused)) *path, List *_list) {
	(void) cname;
	
	print_history_safe(_list, _list->head);
	return (1);
}
