#include "shell.h"
/**
 * verifier_commande - Vérifie et trouve le chemin complet d'une commande
 * @args: Tableau contenant les arguments de la commande
 *
 * Return: Le chemin complet de la commande (alloué dynamiquement),
 *         ou NULL si la commande est invalide.
 */
char *verifier_commande(char **args)
{
	char *commande = NULL;

	if (args == NULL || args[0] == NULL)
	{
		write(STDOUT_FILENO, "Erreur : commande invalide\n", 27);
		return (NULL);
	}

	if (access(args[0], X_OK) != 0)
	{
		commande = chercher_commande(args[0]);
		if (commande == NULL)
		{
			perror(args[0]);
			return (NULL);
		}
		return (commande);
	}
	return (strdup(args[0]));
}

