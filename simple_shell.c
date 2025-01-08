#include "shell.h"

/**
 * main - Entrée principale du programme.
 *
 * Return: 0 en cas de succès, ou un autre code en cas d'erreur.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		/* Affiche le prompt */
		write(STDOUT_FILENO, "($) ", 4);

		/* Lit la ligne de commande */
		nread = getline(&line, &len, stdin);
		if (nread == -1) /* Condition EOF (Ctrl+D) */
		{
			free(line);
			exit(0);
		}

		/* Supprime le saut de ligne */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Exécution de la commande */
		execute_command(line);
	}

	free(line);
	return (0);
}
