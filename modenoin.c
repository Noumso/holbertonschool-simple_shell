#include "shell.h"

/**
 * mode_non_interactif - Gère l'exécution en mode non interactif.
 * Lit les commandes ligne par ligne depuis l'entrée standard,
 * les traite, cherche leur chemin complet si besoin, et les exécute.
 */

void mode_non_interactif(void)
{
	char *ligne = NULL;

	while ((ligne = _getline()) != NULL)
	{
		if (ligne[0] != '\0' && ligne[_strlen(ligne) - 1] == '\n')
			ligne[_strlen(ligne) - 1] = '\0';

		if (ligne[0] == '\0')
		{
			free(ligne);
			continue;
		}

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
