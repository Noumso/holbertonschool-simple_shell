#include "shell.h"

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Tampon contenant la commande entrée.
 * Return: Tableau d'arguments ou NULL si aucune commande.
 */
char **traiter_ligne(char *buffer, char *nom, int count)
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
		write(STDERR_FILENO, nom, strlen(nom));
		printf(": %d: ", count);
		fflush(stdout);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		printf(": not found\n");
		fflush(stdout);
		free(args);
		return (NULL);
	}

	args[0] = commande;


	creer_processus(args);
	free(args);

	return (args);
}
