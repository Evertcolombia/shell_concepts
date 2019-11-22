#include <shell.h>

char *get_path(const char *path_name)
{
	/*index, will go throught the enviroment
	delimiting by '='*/
	char *index;

	/*path =  correct path*/
	char *path;
        
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
			index = strtok(*enviroment, delim);

			/*compare the index content with the path_name, 
			if is true return this adding null at the final
			
			else plus enviroment till fnd the correct name
			*/
			path = _strcmp(index, (char *) path_name);
			if (path == 0)
					return (strtok(NULL, delim));
			enviroment++;

			/*
			_strcmp(index, (char *) path_name) == 0 ? 
				return (strtok(NULL, delim)) : enviroment++;
			*/
	} return (NULL);
}
