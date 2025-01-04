#include "shell.h"

#define DELIM " \t\r\n\a"

/**
 * tknelize - Divise une chaîne en tokens.
 * @buffer: Chaîne de caractères à diviser.
 * Return: Tableau de tokens ou NULL en cas d'erreur.
 */
char **tknelize(char *buffer)
{
	char **args = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	if (!args)
	{
		perror("malloc");
		return (NULL);
	}

	token = _strtok(buffer, DELIM);
	while (token)
	{
		args[i++] = token;

		if (i >= 64)
		{
			args = realloc(args, (i + 1) * sizeof(char *));
			if (!args)
			{
				perror("realloc");
				return (NULL);
			}
		}
		token = _strtok(NULL, DELIM);
	}
	args[i] = NULL;
	return (args);
}
