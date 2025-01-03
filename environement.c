#include "shell.h"

/**
 * executer_env - Imprime l'environnement actuel.
 */
void executer_env(void)
{
	char **env;

	env = environ;
	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

