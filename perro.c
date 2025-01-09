#include "shell.h"

/**
 * _perror - Fonction personnalisée pour afficher les erreurs
 * @msg: Message personnalisé à afficher avant l'erreur
 */
void _perror(char *msg)
{

	fprintf(stderr, "%s: ", msg);

	if (errno != 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
	}
	else
	{

		fprintf(stderr, "Unknown error occurred\n");
	}
}
