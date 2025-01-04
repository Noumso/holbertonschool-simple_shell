#include "shell.h"

/**
 * traiter_ligne - Traite la ligne lue par l'utilisateur.
 * @buffer: Tampon contenant la commande entrée.
 * @taille_buffer: Taille maximale du tampon.
 * Return: Tableau d'arguments ou NULL si aucune commande.
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
	buffer[n_lu - 1] = '\0'; /* Supprimer le caractère '\n' */

	if (strcmp(buffer, "exit") == 0)
		exit(0);

	if (strcmp(buffer, "env") == 0)
	{
		executer_env();
		return (NULL);
	}

	args = tknelize(buffer);
	if (!args || !args[0])
	{
		free(args);
		return (NULL);
	}
	return (args);
}
