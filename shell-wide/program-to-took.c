#include "shell.h"

/*#define BUFSIZE 64
#define LSH_TOK_DELIM ":"*/

char **lsh_split_line(char *arguments)
{
	#define BUFSIZE 64
	#define _DELIM_ ":"

	/*init a bufsize and a position = 0*/
	int bufer_size = BUFSIZE, position = 0;

	/*dobule pointer to create space in memory  fot the bufsize*/
	char **tokens;
	/*will store the tokens*/
	char *token;

	tokens = malloc (bufer_size * sizeof(char*));
	/*if malloc files exit*/
	if (!tokens)
		return(NULL);

	/*take the line argument and splice it with the delimitors*/
	token = strtok(arguments, _DELIM_);
	/*loop while the token is not null*/
	while (token != NULL)
	{
		/*token in position[position] will store what token in order brings*/
		tokens[position] = token;
		position++;

		/*if position is equal or major than bufsize size*/
		if (position >= bufer_size)
		{
				/*bufsize will recives more buufersize  + the lsh_tok_bufsize*/
				bufer_size += BUFSIZE;
				/*reallocate the new tokens using realloc*/
				tokens = realloc(tokens, bufer_size * sizeof(char *));

				/*if tokens ends*/
				if (!tokens)
						return(NULL);
		}
		/*token will be delimited with null*/
		token = strtok(NULL, _DELIM_);
	}
	/*last potision of tokens is nulls*/
	tokens[position] = NULL;
	return tokens;
}
