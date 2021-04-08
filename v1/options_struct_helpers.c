#include "shell.h"

int (*search_in_optionals(char *cname))(char *cname, path_t *_path)
{
	int i = 0;

	cmd_t options[] = {
		{"exit", exit_helper},
	};

	while (i < 1) {
		if (_strcmp(cname, options[i].cname) == 0)
			return (options[i].func);
		i++;
	}
	return (NULL);
}

int exit_helper(char *cname, path_t *_path)
{
	cname = cname;
	free_listint_safe(&_path);
	free(buffer);
	exit(1);
}

int unknown_helper(char *cname, path_t __attribute__((unused)) *path) {
	(void) cname;
	return (1);
}
