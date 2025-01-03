#include "shell.h"

/**
 * main - Point d'entrée pour le shell simple.
 * @argc: Nombre d'arguments.
 * @argv: Tableau des arguments.
 * @env: Variables d'environnement.
 * Return: 0 en cas de succès, autre chose sinon.
 */
int main(int argc, char **argv, char **env)
{
	char *buffer = NULL, **args = NULL;
	size_t len = 0;
	ssize_t n_read;

	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		n_read = getline(&buffer, &len, stdin);
		if (n_read == -1)
		{
			free(buffer);
			exit(0);
		}
		buffer[n_read - 1] = '\0';
		args = tokenize(buffer);
		if (args == NULL || args[0] == NULL)
		{
			free(args);
			continue;
		}
		if (handle_builtins(args, env) == 0)
		{
			free(args);
			continue;
		}
		execute_command(args, env);
		free(args);
	}
	return (0);
}
