#include "shell.h"

char **splitStringPath(char *arguments, char **argvs)
{

        char *delimitador =  ":\n";

	/*init a bufsize and a position = 0*/
	int position = 0, arg_len = 1; //bufer_size = BUFSIZE;

	/*dobule pointer to create space in memory  fot the bufsize*/
	char **tokens;
	/*will store the tokens*/
	char *token;

	arg_len = _strlen(arguments);
	tokens = malloc (arg_len * sizeof(char*));
	/*if malloc files exit*/
	if (tokens == NULL)
		return(NULL);

	/*take the line argument and splice it with the delimitors*/
	token = strtok(arguments, delimitador);
	/*loop while the token is not null*/
	while (token != NULL)
	{
		/*token in position[position] will store what token in order brings*/
		tokens[position] = str_concat(token, "/");
		tokens[position] = str_concat(tokens[position], argvs[0]);

		position++;

		/*if position is equal or major than bufsize size*/
		if (position >= arg_len)
		{
				/*bufsize will recives more buufersize  + the lsh_tok_bufsize*/
				arg_len += arg_len;
				/*reallocate the new tokens using realloc*/
				tokens = realloc(tokens, arg_len * sizeof(char *));

				/*if tokens ends*/
				if (tokens == NULL)
						return(NULL);
		}
		/*token will be delimited with null*/
		token = strtok(NULL, delimitador);
	}
	/*last potision of tokens is nulls*/
	tokens[position] = NULL;
	return tokens;
}
