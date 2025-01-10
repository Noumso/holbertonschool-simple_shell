#include "shell.h"

/**
 * _isdigit - Vérifie si un caractère est un chiffre
 * @c: Caractère à vérifier
 * Cette fonction détermine si un caractère donné est un chiffre (0-9).
 * Return: 1 si le caractère est un chiffre, 0 sinon.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * writext - Vérifie si un caractère est un chiffre
 * @nom: Caractère à vérifier
 * @count: fonction détermine si un caractère
 * @args: donné est un chiffre (0-9).
 * Return: 1 si le caractère est un chiffre, 0 sinon.
 */
void writext(char *nom, int count, char *args)
{
	printf("%s: %d: exit: Illegal number: %s\n", nom, count, args);
}

/**
 * mode_interactif - Gère l'exécution en mode interactif.
 * @nom: Nom du programme.
 */

void mode_interactif(char *nom)
{
	char *buffer = NULL;
	size_t len = 0;
	int count = 0;
	ssize_t nread;
	char *args;

	while (1)
	{
		count++;
		write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&buffer, &len, stdin);
		if (nread == -1)
		{
			if (buffer)
				free(buffer);
			exit(127);
		}
		if (nread > 0 && buffer[nread - 1] == '\n')
			buffer[nread - 1] = '\0';
		if (buffer[0] == '\0')
			continue;
		if (strncmp(buffer, "exit", 4) == 0)
		{
			args = exitenv(buffer);
			writext(nom, count, args);
			free(args);
			continue;
		}
		if (strncmp(buffer, "env", 3) == 0 &&
				(buffer[3] == '\0' || buffer[3] == ' '))
		{
			executer_env();
			continue;
		}

		traiter_ligne(buffer, nom, count);
	}
}


/**
 * exitenv - Gère les commandes spéciales et tokenize une ligne de commande
 * @buffer: Ligne de commande à analyser
 * Cette fonction traite les commandes spéciales comme "exit"
 * Si aucune commande spéciale n'est trouvée, elle retourne une sous-chaîne
 * correspondant aux arguments après la commande
 * Return: Sous-chaîne d'arguments ou NULL si la commande est "exit".
 */

char *exitenv(char *buffer)
{
	size_t len;
	size_t i;
	int j = 0;
	char *args = NULL;

	len = strlen(buffer);
	if (strncmp(buffer, "exit", strlen("exit")) == 0)
	{
		len = strlen(buffer);
		if (len > 4 && _isdigit(buffer[5]))
		{
			exit(atoi(buffer + 5));
		}
	}
	len = strlen(buffer) - 4;
	if (len == 0)
	{
		exit(127);
	}
	if (len > 0)
	{
		args = malloc((len + 1) * sizeof(char));
		if (args == NULL)
		{
			perror("malloc");
			free(args);
		}
		for (i = 5; i < len + 4; i++, j++)
		{
			args[j] = buffer[i];
		}
		args[j] = '\0';
	}
	return (args);
}

/**
 * mode_non_interactif - Gère l'exécution en mode non interactif.
 * @nom: Lit les commandes ligne par ligne depuis l'entrée standard,
 * les traite, cherche leur chemin complet si besoin, et les exécute.
 */

void mode_non_interactif(char *nom)
{
	char *ligne = NULL;
	int count = 0;
	size_t len = 0;
	ssize_t nread;

	while ((nread = getline(&ligne, &len, stdin)) != -1)
	{
		count++;


		if (ligne[nread - 1] == '\n')
			ligne[nread - 1] = '\0';

		if (ligne[0] == '\0')
		{
			free(ligne);
			continue;
		}
		traiter_ligne(ligne, nom, count);
	}


	if (nread == -1)
	{
		perror("Erreur de lecture sur stdin");
		free(ligne);
		exit(0);
	}
	free(ligne);
}
