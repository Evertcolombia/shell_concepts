#include "shell.h"

int main()
{
	char *tokens[10], *new;
	int i, len = 0, ex = 0;
	bool state = true;
	path_t *_path;
	List _list;
	struct stat st;
	int (*execute)(char *cname, path_t *_path, List *_list);

	_path = NULL;
	_path = create_path_list();
	list_init(&_list, NULL);
	
	while (state)
	{
		i = 0;
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "#cisfun$ ", 9);
		
		signal(SIGINT, handleCtrlc);
		buffer = get_line(_path, &_list);
		if (validate_line(_strlen(buffer), buffer) == 1)
			continue;
		len = _strlen(buffer);
		buffer[len - 1] = '\0';
		list_ins_next(&_list, _list.last_in, buffer, len);

		tokens[i] = strtok(buffer, " ");
		while(tokens[i] != NULL)
			tokens[++i] = strtok(NULL, " ");
		
		if (stat(tokens[0], &st) == -1) {
			new = search_path(tokens[0], _path);
			if (new)
				tokens[0] = new;
			else {
				execute = search_in_optionals(tokens[0]);
				if (execute != NULL)
					ex = execute(tokens[0], _path, &_list);
			}
		}
		if (ex == 0)
			fork_process(tokens, buffer);
	}
	return (0);
}
