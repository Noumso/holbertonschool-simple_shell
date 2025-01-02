#include "shell.h"

#define DELIM " \t\r\n\a"

/**
 * tknelize - Tokenise une chaîne de caractères.
 * @buffer: Chaîne de caractères à tokeniser
 *
 * Return: Un tableau de chaînes de caractères (arguments) ou NULL.
 */
char **tknelize(char *buffer)
{
	char **args = malloc(64 * sizeof(char *));
	char *token;
	int position = 0;

	if (!args)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(buffer, DELIM);
	while (token != NULL)
	{
		args[position] = token;
		position++;

		if (position >= 64)
		{
			args = realloc(args, (position + 1) * sizeof(char *));
			if (!args)
			{
				perror("realloc");
				return (NULL);
			}
		}

		token = strtok(NULL, DELIM);
	}

	args[position] = NULL;
	return (args);
}
