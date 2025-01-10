#include "shell.h"
#define DELIM " \t\r\n\a"
#define INITIAL_TOKENS_SIZE 64

/**
 * free_args - Libère un tableau de tokens.
 * @args: Tableau de tokens à libérer.
 */
void free_args(char **args)
{
	if (args)
	{
		free(args);
	}
}

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Tampon contenant la commande entrée.
 * @nom: Nom du programme.
 * @count: Un compteur.
 * Return: Tableau d'arguments ou NULL si aucune commande ou erreur.
 */
char **traiter_ligne(char *buffer, char *nom, int count)
{
	char **args;
	char *commande;

	args = tknelize(buffer);
	if (args == NULL)
	{
		free(buffer);
		return (NULL);
	}
	commande = chercher_commande(args[0]);
	if (commande == NULL)
	{
		printf("%s: %d: %s: not found\n", nom, count, args[0]);
		free_args(args);
		return (NULL);
	}
	args[0] = strdup(commande);
	free(commande);
	if (!args[0])
	{
		perror("strdup");
		free_args(args);
		return (NULL);
	}
	creer_processus(args);
	free(buffer);

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
		free(path);
	return (NULL);
	path_copy = strdup(path);
	repertoire = strtok(path_copy, ":");
	while (repertoire)
	{
		chemin_complet = malloc(strlen(repertoire) + longueur_commande + 2);
		if (!chemin_complet)
		{
			free(chemin_complet);
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
	free(path);
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
 * @buffer: Chaîne de caractères à diviser (l'appelant gère sa mémoire).
 * Return: Tableau de tokens ou NULL en cas d'erreur.
 */
char **tknelize(char *buffer)
{
	int i = 0, tokens_size = 64;
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
			tokens_size *= 2;
			temp = realloc(args, tokens_size * sizeof(char *));
			if (!temp)
			{
				perror("realloc");
				free_args(args);
				return (NULL);
			}
			args = temp;
		}

		token = strtok(NULL, DELIM);
	}

	args[i] = NULL; /* Terminer le tableau par NULL */
	return (args);
}

/**
 * _getenv - Gets The Value Of Enviroment Variable By Name
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (strncmp(name, environ[i], nl) == 0)
		{
			vl = strlen(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';
			return (value);
		}
	}
	return (NULL);
}
