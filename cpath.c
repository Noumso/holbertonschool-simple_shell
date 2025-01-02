#include "shell.c"
/**
 * chercher_commande - Cherche une commande dans les répertoires définis par PATH
 * @commande: Commande à chercher
 *
 * Retourne: Le chemin complet de la commande si trouvée, NULL sinon.
 */
char *chercher_commande(char *commande)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *repertoire;
	char *chemin_complet;
	struct stat buffer;

	if (path_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	repertoire = strtok(path_copy, ":");
	while (repertoire != NULL)
	{
		chemin_complet = malloc(strlen(repertoire) + strlen(commande) + 2);
		if (chemin_complet == NULL)
		{
			perror("malloc");
			free(path_copy);
			return (NULL);
		}
		strcpy(chemin_complet, repertoire);
		strcat(chemin_complet, "/");
		strcat(chemin_complet, commande);
		if (access(chemin_complet, X_OK) == 0)
		{
			free(path_copy);
			return (chemin_complet);
		}

		free(chemin_complet);
		repertoire = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
