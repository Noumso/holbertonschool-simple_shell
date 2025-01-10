#include "shell.h"
#define DELIM " \t\r\n\a"
#define INITIAL_TOKENS_SIZE 64

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Tampon contenant la commande entrée.
 * @nom: nom du prohgramme
 * @count: un compteur
 * Return: Tableau d'arguments ou NULL si aucune commande.
 */
char **traiter_ligne(char *buffer, char *nom, int count)
{
	char **args;
	char *commande;

	args = tknelize(buffer);
	if (args == NULL)
	{
		return (NULL);
	}


	commande = chercher_commande(args[0]);
	if (commande == NULL)
	{
		write(STDERR_FILENO, nom, strlen(nom));
		printf(": %d: ", count);
		fflush(stdout);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		printf(": not found\n");
		fflush(stdout);
		free(args);
		return (NULL);
	}

	args[0] = commande;


	creer_processus(args);
	free(args);

	return (args);
}

/**
 * chercher_commande - Recherche une commande dans les répertoires du PATH
 * @commande: Nom de la commande à rechercher
 *
 * Return: Le chemin complet de la commande si trouvée, sinon NULL
 */

char *chercher_commande(char *commande)
{
	struct stat buffer;
	char *path, *path_copy, *repertoire, *chemin_complet;
	size_t longueur_commande = strlen(commande);

	if (strchr(commande, '/') != NULL)
	{
		if (stat(commande, &buffer) == 0)
			return (strdup(commande));
		return (NULL);
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
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
		if (stat(chemin_complet, &buffer) == 0)
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



/**
 * creer_processus - Crée un processus pour exécuter la commande
 * @args: Tableau des arguments de la commande à exécuter
 */
void creer_processus(char **args)
{
	pid_t pid;
	int statut;

	pid = fork();
	if (pid == -1)
	{
		perror("Erreur fork");
		return;
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &statut, 0);
	}
}

/**
 * tknelize - Divise une chaîne en tokens.
 * @buffer: Chaîne de caractères à diviser.
 * Return: Tableau de tokens ou NULL en cas d'erreur.
 */

char **tknelize(char *buffer)
{
	int i = 0, tokens_size = INITIAL_TOKENS_SIZE;
	char **args;
	char *token;
	char **temp;

	args = malloc(tokens_size * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(buffer, DELIM);
	while (token)
	{
		args[i++] = token;
		if (i >= tokens_size)
		{
			tokens_size += INITIAL_TOKENS_SIZE;
			temp = realloc(args, tokens_size * sizeof(char *));
			if (!temp)
			{
				perror("realloc");
				free(args);
				return (NULL);
			}
			args = temp;
		}

		token = strtok(NULL, DELIM);
	}


	args[i] = NULL;
	return (args);
}

/**
 * _getenv - Récupère la valeur d'une variable d'environnement.
 * @name: Nom de la variable d'environnement.
 * Return: Valeur de la variable ou NULL si introuvable.
 */
char *_getenv(char *name)
{
	size_t len = strlen(name);
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
	}
	return (NULL);
}
