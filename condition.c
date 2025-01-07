#include "shell.h"

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Tampon contenant la commande entrée.
 * Return: Tableau d'arguments ou NULL si aucune commande.
 */
char **traiter_ligne(char *buffer)
{
	char **args;
	char *commande;

	args = tknelize(buffer);
	if (args == NULL)
	{
		return (NULL);
	}


	commande = chercher_commande(args[0]);
	if (commande == NULL)
	{
		write(STDERR_FILENO, ": Commande introuvable\n", 23);
		free(args);
		return (NULL);
	}


	args[0] = commande;


	creer_processus(args);
	free(args);

	return (args);
}
