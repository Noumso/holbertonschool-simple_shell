#include "shell.h"

/**
 * main - Point d'entrée pour le shell simple
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char buffer[TAILLE_BUFFER];
	char **args;
	char *commande;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		args = traiter_ligne(buffer, TAILLE_BUFFER);
		if (args == NULL)
			continue;

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
	return (0);
}

