#include "shell.h"

/**
 * chercher_commande - Recherche une commande dans les répertoires du PATH
 * @commande: Nom de la commande à rechercher
 *
 * Return: Le chemin complet de la commande si trouvée, sinon NULL
 */
char *chercher_commande(char *commande)
{
	char *path = getenv("PATH");
	char *path_copy, *repertoire, *chemin_complet;
	size_t longueur_commande;
	struct stat buffer;

	if (stat(commande, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
	{
		return (_strdup(commande));
	}
	if (!path)
		return (NULL);
	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);
	longueur_commande = _strlen(commande);
	repertoire = _strtok(path_copy, ":");
	while (repertoire)
	{
		chemin_complet = malloc(_strlen(repertoire) + longueur_commande + 2);
		if (!chemin_complet)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(chemin_complet, repertoire);
		_strcat(chemin_complet, "/");
		_strcat(chemin_complet, commande);
		if (stat(chemin_complet, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (chemin_complet);
		}
		free(chemin_complet);
		repertoire = _strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
