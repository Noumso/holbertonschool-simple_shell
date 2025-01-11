#include "shell.h"

/**
 * find_command_in_path - Recherche le chemin absolu d'une commande.
 * @command: Le nom de la commande à rechercher (exemple : "ls").
 *
 * Retourne:
 * - Un pointeur vers une chaîne contenant le chemin complet de la commande
 *   si elle est trouvée (la mémoire est allouée dynamiquement).
 * Return: NULL si la commande n'est pas trouvée ou en cas d'erreur.
 */
char *find_command_in_path(char *command)
{
	char *path = get_env_var("PATH");
	char *dir, *full_path;
	size_t len;

	if (!path)
		return (NULL);

	dir = strtok(path, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
			return (NULL);

		snprintf(full_path, len, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * get_env_var - Récupère la valeur d'une variable d'environnement.
 * @name: Le nom de la variable d'environnement à chercher (exemple : "PATH").
 *
 * Retourne:
 * - Un pointeur vers la valeur de la variable d'environnement si elle existe.
 * Return: NULL si la variable n'est pas trouvée.
 */
char *get_env_var(const char *name)
{
	char *env_var, *value;
	int i, len = strlen(name);

	for (i = 0; environ[i]; i++)
	{
		env_var = environ[i];
		if (strncmp(env_var, name, len) == 0 && env_var[len] == '=')
		{
			value = env_var + len + 1;
			return (value);
		}
	}
	return (NULL);
}
