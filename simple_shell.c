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
	ssize_t n_lu;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		n_lu = lire_entree(buffer, TAILLE_BUFFER);
		if (n_lu == -1)
		{
			perror("read");
			continue;
		}
		if (n_lu == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (buffer[n_lu - 1] == '\n')
			buffer[n_lu - 1] = '\0';
		if (buffer[0] == '\0')
			continue;
		args = tknelize(buffer);
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}
		commande = chercher_commande(args[0]);
		if (commande == NULL)
		{
			write(STDOUT_FILENO, "Commande introuvable\n", 21);
			free(args);
			continue;
		}
		args[0] = commande;
		creer_processus(args);
	}
	return (0);
}
