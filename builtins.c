#include "shell.h"

/**
 * handle_builtins - Gère les commandes intégrées.
 * @args: Tableau d'arguments.
 * @env: Variables d'environnement.
 * Return: 0 si une commande intégrée est exécutée, 1 sinon.
 */
int handle_builtins(char **args, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(0);
	}
	if (strcmp(args[0], "env") == 0)
	{
		afficher_env(env);
		return (0);
	}
	return (1);
}

/**
 * afficher_env - Affiche les variables d'environnement.
 * @env: Tableau de variables d'environnement.
 */
void afficher_env(char **env)
{
	for (int i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

