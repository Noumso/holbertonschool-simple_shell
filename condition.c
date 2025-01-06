#include "shell.h"

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Tampon contenant la commande entrée.
 * @taille_buffer: Taille maximale du tampon.
 * Return: Tableau d'arguments ou NULL si aucune commande.
 */

char **traiter_ligne(char *buffer)
{
	char **args;
	char *commande;
	while (1)
	{
		ssize_t n_lu = read(STDIN_FILENO, buffer, strlen(buffer));
		if (n_lu == -1)
		{
			perror("read");
			continue;
		}

		if (n_lu == 0)
		{
			exit(0); /* Fin du flux ou EOF */
		}

		buffer[n_lu - 1] = '\0'; /* Supprime le caractère de nouvelle ligne */

		/* Appeler traiter_ligne pour analyser la commande */
		args = exitenv(buffer);
		if (args == NULL)
		{
			continue; /* Commande spéciale ou ligne vide */
		}

		commande = chercher_commande(args[0]);
		if (commande == NULL)
		{
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, ": Commande introuvable\n", 23);
			free(args);
			continue;
		}

		args[0] = commande;
		creer_processus(args);
		free(args);
	}
}
