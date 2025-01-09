#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * exitenv - Gère les commandes spéciales et tokenize une ligne de commande
 * @buffer: Ligne de commande à analyser
 * Cette fonction traite les commandes spéciales comme "exit"
 * Si aucune commande spéciale n'est trouvée, elle retourne une sous-chaîne
 * correspondant aux arguments après la commande
 * Return: Sous-chaîne d'arguments ou NULL si la commande est "exit".
 */

char *exitenv(char *buffer)
{
	size_t i, len;
	int j = 0;
	char *args = NULL;

	len = strlen(buffer);
	if (strncmp(buffer, "exit", strlen("exit")) == 0)
	{
		len = strlen(buffer);
		if (len > 4 && isdigit(buffer[5]))
		{
			exit(atoi(buffer + 5));
		}
		else
		{
			exit(0);
		}
	}
	len = strlen(buffer) - 4;
	if (len > 0)
	{
		args = malloc((len + 1) * sizeof(char));
		if (args == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		for (i = 4; i < strlen(buffer); i++, j++)
		{
			args[j] = buffer[i];
		}
		args[j] = '\0';
		return (args);
	}
	return (NULL);
}
