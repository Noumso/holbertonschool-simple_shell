#include "shell.h"

/**
 * execute_command - Exécute une commande.
 * @args: Tableau d'arguments.
 * @env: Variables d'environnement.
 */
void execute_command(char **args, char **env)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}

