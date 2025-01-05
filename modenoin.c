#include "shell.h"

/**
 * mode_non_interactif - Gère l'exécution en mode non interactif.
 * Cette fonction lit les commandes ligne par ligne depuis l'entrée standard,
 * les traite, cherche leur chemin complet si besoin, et les exécute.
 */

void mode_non_interactif(void)
{
	char buffer[TAILLE_BUFFER];
	char *ligne;
	char **args;
	char *commande;

	while (lire_entree(buffer, TAILLE_BUFFER) > 0)
	{
		ligne = _strtok(buffer, "\n");
		while (ligne != NULL)
		{
			args = traiter_ligne(ligne, TAILLE_BUFFER);
			if (args == NULL)
			{
				ligne = _strtok(NULL, "\n");
				continue;
			}

			commande = chercher_commande(args[0]);
			if (commande == NULL)
			{
				write(STDOUT_FILENO, "Commande introuvable\n", 21);
				free(args);
				ligne = _strtok(NULL, "\n");
				continue;
			}

			args[0] = commande;
			creer_processus(args);
			free(args);

			ligne = _strtok(NULL, "\n");
		}
	}
}
