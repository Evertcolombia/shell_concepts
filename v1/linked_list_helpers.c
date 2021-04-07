#include "shell.h"

path_t *add_node(path_t **head, char *pathname)
{
	path_t *new;

	if (head == NULL) {
		perror("Error");
		exit(1);
	}
	new = (path_t *) malloc(sizeof(path_t));
	if (new == NULL) {
		perror("Error");
		exit(1);
	}

	new->pathname = _strdup(pathname);
	new->len = _strlen(new->pathname);
	new->next = *head, *head = new;
	return (new);
}

char *search_path(char *pathname, path_t *head)
{
	char *copy;
	struct stat st;
	while (head != NULL)
	{
		copy = _strdup(head->pathname);
		copy = _strcat(copy, "/");
		copy = _strcat(copy, pathname);
		if (stat(copy, &st) == 0)
			return (copy);
		head = head->next;
	}
	return (NULL);
}
size_t print_listint_safe(path_t *head)
{
	size_t count = 0;

        while (head != NULL)
        {
                printf("[%p] %s\n", (void *)head, head->pathname);
                count++;
                if ((head->next) >= head)
                {
                        printf("-> [%p] %s\n", (void *)head->next, head->next->pathname);
                        return (count);
                }
                head = head->next;
        } return (count);
}
