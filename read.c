#include "shell.h"

/**
 * lire_entree - Lit l'entrée utilisateur à l'aide de read
 * @buffer: Le tampon pour stocker l'entrée
 * @taille: La taille maximale du tampon
 *
 * Return: Le nombre de caractères lus, ou -1 en cas d'erreur.
 */

ssize_t lire_entree(char *buffer, size_t taille)
{
	ssize_t n_lu = read(STDIN_FILENO, buffer, taille - 1);
	printf("%ld\n", n_lu);

	if (n_lu > 0)
	{
		buffer[n_lu] = '\0';
	}
	return (n_lu);
}

