#include "shell.h"

/**
 * mode_interactif - Gère l'exécution en mode interactif.
 *@nom: Affiche une invite ("$"), lit les commandes utilisateur,
 * et les traite en conséquence.
 */
void mode_interactif(char *nom)
{
	char *buffer;
	int count = 0;

	while (1)
	{
		count++;
		write_custom(STDOUT_FILENO, "$ ", 2);
		buffer = _getline();
		if (buffer == NULL)
		{
			continue;
		}
		if (_strncmp(buffer, "exit", 4) == 0)
		{
			buffer = exitenv(buffer);
		}
		if (_strncmp(buffer, "env", 3) == 0 &&
				(buffer[3] == '\0' || buffer[3] == ' '))
		{
			executer_env();
			my_free(buffer);
			continue;
		}
		if (buffer[0] == '\0')
		{
			my_free(buffer);
			continue;
		}
		traiter_ligne(buffer, nom, count);
		my_free(buffer);
	}
}
