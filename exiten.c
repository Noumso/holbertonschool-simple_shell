#include "shell.h"

/**
 * exitenv - Gère les commandes spéciales et tokenize une ligne de commande
 * @buffer: Ligne de commande à analyser
 *
 * Cette fonction traite les commandes spéciales comme "exit" et "env".
 * Si aucune commande spéciale n'est trouvée, elle tokenize la ligne
 * pour créer un tableau d'arguments.
 *
 * Return: void
 */

char *exitenv(char *buffer)
{
	if (_strncmp(buffer, "exit", 4) == 0)
	{
		exit(0); /* Quitte le programme */
	}

	if (_strncmp(buffer, "env", 3) == 0)
	{
		executer_env(); /* Affiche les variables d'environnement */
		return (NULL);
	}

	return (buffer);
}

