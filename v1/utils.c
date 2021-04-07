#include "shell.h"

int _strlen(char *s)
{
	char *cp = s;
	
	while (*cp != '\0')
		cp++;
	return (cp - s);
}

char *_strcpy(char *dest, char *src)
{
	char *cp = dest;
	printf("sisass\n");
	while ((*dest++ = *src++))
		printf("1\n");
	dest = cp;
	return (dest);
}

int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++);
	{
		if (*s1 == 61)
			return(0);
	}
	return(*s1 - *s2);
}

char *_strdup(char *str)
{
	int a, i;
	char *p;
	a = 0;

	if (str == NULL)
		return (NULL);
	
	while (str[a] != '\0')
		a++;
	a++;
	
	p = malloc(sizeof(char) * a);
	if (p == NULL)
		return (NULL);

	for (i = 0; i <= a; i++)
		p[i] = str[i];
	return (p);
}

char *_strcat(char *dest, char *src)
{
        char *head = dest;

        for (; *dest != '\0'; dest++)
                ;
        while ((*dest++ = *src++))
                ;
        dest = head;
        return (dest);
}
