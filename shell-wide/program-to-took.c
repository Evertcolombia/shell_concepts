#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM ":"

char **lsh_split_line(char *line)
{
	/*init a bufsize and a position = 0*/
	int bufsize = LSH_TOK_BUFSIZE, position 0;

	/*dobule pointer to create space in memory  fot the bufsize*/
	char **tokens = malloc (bufsize * sizeof(char*));
	/*will store the tokens*/
	char *token;

	/*if malloc files exit*/
	if (!tokens)
		return(1);

	/*take the line argument and splice it with the delimitors*/
	token = strtok(line, LSH_TOK_DELIM);
	/*loop while the token is not null*/
	while (token != NULL)
	{
		/*token in position[position] will store what token in order brings*/
		tokens[position] = token;
		position++;

		/*if position is equal or major than bufsize size*/
		if (position >= bufsize)
		{
				/*bufsize will recives more buufersize  + the lsh_tok_bufsize*/
				bufsize += LSH_TOK_BUFSIZE;
				/*reallocate the new tokens using realloc*/
				tokens = realloc(tokens, bufsize, * sizeof(char *));

				/*if tokens ends*/
				if (!tokens)
				{
						return(1);
				}
		}
		/*token will be delimited with null*/
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	/*last potision of tokens is nulls/
	tokens[position] = NULL;
	return tokens;
}
