#include "shell.h"

/**
 * exitenv - Gère les commandes spéciales et tokenize une ligne de commande
 * @buffer: Ligne de commande à analyser
 * Cette fonction traite les commandes spéciales comme "exit"
 * Si aucune commande spéciale n'est trouvée, elle retourne une sous-chaîne
 * correspondant aux arguments après la commande
 * Return: Sous-chaîne d'arguments ou NULL si la commande est "exit".
 */

char *exitenv(char *buffer,char *nom, int count)
{
	size_t len;
	size_t i;
	int j = 0;
	char *args = NULL;

	len = _strlen(buffer);
	if (_strncmp(buffer, "exit", _strlen("exit")) == 0)
	{
		len = _strlen(buffer);
		if (len > 4 && _isdigit(buffer[5]))
		{
			exit(atoi(buffer + 5));
		}
	}
	len = _strlen(buffer) - 4;
	if (len == 1)
	{
		exit(127);
	}
	if (len > 0)
	{
		args = _malloc((len + 1) * sizeof(char));	
		if (args == NULL)
		{
			_perror("malloc");
		}
		for (i = 4; i < len + 3; i++, j++)
		{
			args[j] = buffer[i];
		}
		args[j] = '\0';
		writext(nom, count, args);
	}
	return (args);
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


/**
 * writext - Vérifie si un caractère est un chiffre
 * @nom: Caractère à vérifier
 * @count: fonction détermine si un caractère 
 * @args: donné est un chiffre (0-9).
 * Return: 1 si le caractère est un chiffre, 0 sinon.
 */
void writext(char *nom, int count, char *args)
{
	write(STDERR_FILENO, nom, strlen(nom));
	printf(": %d: exit: Illegal number: %s", count,args);
}
