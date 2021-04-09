#include "shell.h"

void list_init(List *list, void (*destroy)(void *data)) {
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->last_in = NULL;
	list->tail = NULL;

	return;
}

void list_destroy(List *list)
{
	void *data;
	while (list_size(list) > 0) {
		list_rem_next(list, NULL, (void **)&data);
			/*list->destroy(data);*/
	}
	free(list->head);
	/*_memset(list, 0, sizeof(List));*/
	return;
}

int list_ins_next(List *list, hstr_t *element, const void *data, int len)
{
	hstr_t *new;

	new = (hstr_t *) malloc(sizeof(hstr_t));
	if (new == NULL)
		return (-1);
	new->data = (void *)data;
	new->len = len;

	if (element == NULL) {
		if (list_size(list) == 0)
			list->tail = new;
	
		new->next = list->head;
		list->head = new;
	}
	else {
		if (element->next == NULL)
			list->tail = new;
		new->next = element->next;
		element->next = new;
	}
	list->last_in = new;
	list->size++;
	return (0);
}

int list_rem_next(List *list, hstr_t *element, void **data)
{
	hstr_t *old;

	if (list_size(list) == 0)
		return (-1);

	if (element == NULL) {
		*data = list->head->data;
		old = list->head;
		list->head = list->head->next;
	}
	else {
		if (element->next == NULL)
			return (-1);
	
		*data = element->next->data;
		old = element->next;
		element->next = element->next->next;

		if (element->next == NULL)
			list->tail = element;
	}
	free(*data);
	free(old);
	list->size--;
	return(0);
}

void print_history_safe(List *list, hstr_t *head)
{
	int i = 0;
	hstr_t *cp = head;

	if (list_size(list) == 0)
		return;
	
	while (i < list_size(list)) {
		write(1, cp->data, cp->len - 1);
		write(1, "\n", 1);
		cp = cp->next;
		i++;
	}
	return;
}
