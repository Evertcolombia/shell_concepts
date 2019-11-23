#include <stdlib.h>

/**
 * *str_concat - concatenate two strings
 * @s1: string
 * @s2: string
 *
 * Return: pointer to a string (str)
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, z = 0, h = 0, count, lenght, lenghtTotal;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[i])
		i++;
	lenghtTotal = i - 1;
    lenght = lenghtTotal;

	while (s2[z])
		z++;
	lenghtTotal += z + 1;

	str = malloc(sizeof(char) * lenghtTotal);
	if (str == NULL)
		return (NULL);

	for (count = 0; count <= lenghtTotal + 1; count++)
	{
		if (count > lenght)
			str[count] = s2[h], h++;
		else
			str[count] = s1[count];
	}
	return (str);
}