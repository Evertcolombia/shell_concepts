#include "shell.h"
#include <stdio.h>
int main (void)
{
	/*index, will go throught the enviroment
	delimiting by '='*/
	char *index;

	/*path =  correct path*/
	char *path = "PATH";

        int new_path,  i = 0;

	/*enviroment from the header, from the environ
	variable*/
	char **enviroment;

	char *delimitator = "=";

	enviroment = environ;

	/*whle enviroment can be traverse look for the correct
	index */
	while (*enviroment)
	{
			/*delimit the enviroment in  index*/
			index = strtok(*enviroment, delimitator);

			/*compare the index content with the path_name,
			if is true return this adding null at the final

			else plus enviroment till fnd the correct name
			*/
			new_path = _strcmp(index, (char *) path);
			if (new_path == 0)
                        {
                                printf("new_path = %i\n, index: %i", new_path, i);
                                return (1);
					//return (strtok(NULL, delimitator));
                        }
			enviroment++;
                        i++;

			/*
			_strcmp(index, (char *) path_name) == 0 ?
				return (strtok(NULL, delim)) : enviroment++;
			*/
	} return (0);
}
