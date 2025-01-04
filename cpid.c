#include "shell.h"


/**
 * creer_processus - Crée un processus pour exécuter la commande
 * @args: Tableau des arguments de la commande à exécuter
 */
void creer_processus(char **args)
{
	pid_t pid;
	int statut;

	pid = fork();
	if (pid == -1)
	{
		perror("Erreur fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &statut, 0);
	}
}
