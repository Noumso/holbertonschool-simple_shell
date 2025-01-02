#include "shell.h"
/**
 * chercher_commande - Cherche une commande dans les répertoires path
 * @commande: Commande à chercher
 *
 * Return: Le chemin complet de la commande si trouvée, NULL sinon.
 */
char *chercher_commande(char *commande)
{
	char *path = getenv("PATH");
	char *path_copy, *repertoire, *chemin_complet;
	size_t longueur_commande;
	struct stat buffer;

	if (!path)
		return (NULL);

	path_copy = strdup(path); /* Copie de PATH */
	if (!path_copy)
		return (NULL);

	longueur_commande = strlen(commande);
	repertoire = strtok(path_copy, ":");

	while (repertoire)
	{
		chemin_complet = malloc(strlen(repertoire) + longueur_commande + 2);
		if (!chemin_complet)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(chemin_complet, repertoire);
		strcat(chemin_complet, "/");
		strcat(chemin_complet, commande);

		if (stat(chemin_complet, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
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
