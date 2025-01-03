#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "shell.h"

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Le tampon qui contient la ligne entrée par l'utilisateur.
 * @taille_buffer: La taille maximale du tampon.
 *
 * Return: Un tableau de chaînes de caractères représentant
 * les arguments de la commande,
 *         ou NULL en cas d'erreur ou de ligne vide.
 */
char **traiter_ligne(char *buffer, size_t taille_buffer)
{
	ssize_t n_lu;
	char **args;

	n_lu = read(STDIN_FILENO, buffer, taille_buffer);
	if (n_lu == -1)
	{
		perror("read");
		return (NULL);
	}
	if (n_lu == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}

	if (buffer[n_lu - 1] == '\n')
		buffer[n_lu - 1] = '\0';

	if (buffer[0] == '\0')
		return (NULL);
	if (strcmp(buffer, "exit") == 0)
	{
		exit(0);
	}

	args = tknelize(buffer);
	if (args == NULL || args[0] == NULL)
	{
		free(args);
		return (NULL);
	}
	return (args);
}
