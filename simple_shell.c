#include "shell.h"

/**
 * main - Point d'entrée pour le shell simple
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char buffer[TAILLE_BUFFER]; /* Tampon pour la commande entrée */
	char **args;                /* Tableau d'arguments pour la commande */
	char *commande;             /* Chemin complet de la commande */

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		/* Traiter la ligne d'entrée et obtenir les arguments */
		args = traiter_ligne(buffer, TAILLE_BUFFER);
		if (args == NULL)
			continue; /* Si aucune commande n'est entrée, on recommence */

		/* Chercher le chemin complet de la commande */
		commande = chercher_commande(args[0]);
		if (commande == NULL)
		{
			write(STDOUT_FILENO, "Commande introuvable\n", 21);
			free(args); /* Libérer la mémoire allouée pour args */
			continue;
		}

		/* Remplacer la commande par son chemin complet */
		args[0] = commande;

		/* Créer le processus pour exécuter la commande */
		creer_processus(args);

		/* Libérer la mémoire allouée pour args */
		free(args);
	}

	return (0);
}
