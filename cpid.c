#include "shell.h"
/**
 * creer_processus - Crée un processus enfant et exécute une commande
 * @buffer: Commande à exécuter
 *
 * Retourne: Rien.
 */
void creer_processus(char *buffer)
{
	pid_t pid;
	int statut;
	char **args;
	char *commande;

	args = toknelize(buffer);
	if (args == NULL)
	{
		write(STDOUT_FILENO, "Erreur : commande invalide\n", 27);
		return;
	}
	commande = verifier_commande(args);
	if (commande == NULL)
	{
		free(args);
		return;
	}
	args[0] = commande;
	pid = fork();
	if (pid == -1)
	{
		perror("Erreur fork");
		free(args);
		free(commande);
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			free(args);
			free(commande);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &statut, 0);
	}
}
