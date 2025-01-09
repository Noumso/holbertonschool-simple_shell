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
		if (write_custom(STDOUT_FILENO, *env, _strlen(*env)) == -1)
		{
			_perror("Erreur d'écriture de l'environnement");
			return;
		}
		if (write_custom(STDOUT_FILENO, "\n", 1) == -1)
		{
			_perror("Erreur d'écriture du saut de ligne");
			return;
		}

		env++;
	}
}
