#include "shell.h"

/**
 * mode_interactif - Gère l'exécution en mode interactif.
 * Cette fonction affiche un invite ("$") et attend les commandes utilisateur.
 * Les commandes sont traitées, cherchées dans le PATH si besoin exécutées.
 */
void mode_interactif(void)
{
	char buffer[TAILLE_BUFFER]; /* Tampon pour la commande entrée */
	char **args;
	char *commande;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		args = traiter_ligne(buffer);
		if (args == NULL)
			continue; /* Si aucune commande n'est entrée, on recommence */

		commande = chercher_commande(args[0]);
		if (commande == NULL)
		{
			write(STDOUT_FILENO, "Commande introuvable\n", 21);
			free(args);
			continue;
		}

		args[0] = commande;
		creer_processus(args);

		free(args);
	}
}
