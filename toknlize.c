#include "shell.h"

/**
 * toknelize - Divise une chaîne de caractères en tokens (arguments)
 * @buffer: La chaîne de caractères à diviser (entrée de l'utilisateur)
 *
 * Return: Un tableau de chaînes de caractères (les arguments).
 */
char **toknelize(char *buffer)
{
	char **args = malloc(TAILLE_BUFFER * sizeof(char *));
	char *token;
	int i = 0;

	if (args == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(buffer, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
