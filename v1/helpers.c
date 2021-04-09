  
#include "shell.h"
/**
 * *_calloc - call
 * @nmemb: n
 * @size: size
 * Return: Success: new memory , Fail: NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *memory;

	if (nmemb == 0 || size == 0)
		return (NULL);
	memory = malloc(nmemb * size);
	if (memory == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		*(memory + i) = 0;
	return ((void *)memory);
}

/**
 * *_memset - fills memory with a constant byte
 * @s: array memory
 * @b: constant byte
 * @n: memory length
 * Return: array *s
 */
char *_memset(char *s, char b, unsigned int n)
{
	while (n--)
		s[n] = b;
	return (s);
}
