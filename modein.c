#include "shell.h"

/**
 * mode_interactif - Gère l'exécution en mode interactif.
 * Cette fonction affiche une invite ("$") et
 * attend les commandes utilisateur.
 * Les commandes sont traitées, cherchées dans le PATH si besoin,
 * puis exécutées.
 */

void mode_interactif(void)
{
	char *buffer = NULL;
	size_t taille = 0;
	ssize_t n_lus;

	while (1)
	{

		write(STDOUT_FILENO, "$ ", 2);


		n_lus = getline(&buffer, &taille, stdin);
		if (n_lus == -1)
		{

			if (feof(stdin))
				break;
			perror("Erreur de lecture");
			continue;
		}


		if (buffer[n_lus - 1] == '\n')
			buffer[n_lus - 1] = '\0';


		if (traiter_ligne(buffer) == NULL)
		{
			write(STDERR_FILENO, "Erreur lors du traitement de la commande\n", 42);
			continue;
		}
	}

	free(buffer);
}
