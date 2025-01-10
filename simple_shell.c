#include "shell.h"

/**
 * main - Point d'entrée principal du programme.
 * @argc: Cette fonction détecte si l'exécution doit se faire
 * @argv: ven mode inta ou non
 * interactif en vérifiant si l'entrée standard est un terminal.
 *
 * Return: Toujours 0 (succès).
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	if (isatty(STDIN_FILENO))
	{
		mode_interactif(argv[0]);
	}
	else
	{
		mode_non_interactif(argv[0]);
	}
	return (0);
}

/**
 * executer_env - Imprime l'environnement actuel.
 */
void executer_env(void)
{
	char **env;

	env = environ;
	while (*env)
	{
		if (write(STDOUT_FILENO, *env, strlen(*env)) == -1)
		{
			perror("Erreur d'écriture de l'environnement");
			return;
		}
		if (write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("Erreur d'écriture du saut de ligne");
			return;
		}

		env++;
	}
}
