#include "shell.h"

/**
 * mode_non_interactif - Gère l'exécution en mode non interactif.
 * Lit les commandes ligne par ligne depuis l'entrée standard,
 * les traite, cherche leur chemin complet si besoin, et les exécute.
 */

void mode_non_interactif(void)
{
	char *ligne = NULL;
	size_t taille = 0;
	ssize_t n_lus;

	while ((n_lus = getline(&ligne, &taille, stdin)) != -1)
	{

		if (n_lus > 0 && ligne[n_lus - 1] == '\n')
			ligne[n_lus - 1] = '\0';


		if (ligne[0] == '\0')
			continue;


		if (traiter_ligne(ligne) == NULL)
		{
			write(STDERR_FILENO, "Erreur lors du traitement de la commande\n", 42);
		}
	}

	free(ligne);

	if (!feof(stdin))
	{
		perror("Erreur de lecture sur stdin");
		exit(EXIT_FAILURE);
	}
}
