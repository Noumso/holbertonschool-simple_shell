#include "shell.h"

/**
 * handle_exit - Gère la commande interne 'exit'.
 */
void my_exit(char *nom, int count, char *line)
{
	size_t len;
	size_t i;
	int j = 0;
	char *args = NULL;

	len = strlen(line);
	if (strncmp(line, "exit", strlen("exit")) == 0)
	{
		len = strlen(line);
		if (len > 4 && _isdigit(line[5]))
		{
			exit(atoi(line + 5));
		}
	}
	len = strlen(line) - 4;
	if (len == 0)
	{
		exit(127);
	}
	if (len > 0)
	{
		args = malloc((len + 1) * sizeof(char));
		if (args == NULL)
		{
			perror("malloc");
		}
		for (i = 5; i < len + 4; i++, j++)
		{
			args[j] = line[i];
		}
		args[j] = '\0';
	}
	printf("%s: %d: exit: Illegal number: %s\n", nom, count, args);
}

/**
 * _isdigit - Vérifie si un caractère est un chiffre
 * @c: Caractère à vérifier
 * Cette fonction détermine si un caractère donné est un chiffre (0-9).
 * Return: 1 si le caractère est un chiffre, 0 sinon.
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
