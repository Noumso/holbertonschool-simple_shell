#include "shell.h"

/**
 * handle_exit - Gère la commande 'exit'.
 * @args: Les arguments passés à la commande (ex. args[0] = "exit").
 *
 * Retourne:
 * 1 si le programme doit continuer.
 * - 0 si le programme doit se terminer.
 */
void handle_exit(char **args)
{
	int exit_status;

	if (args[1] == NULL)
	{
		exit(0);
	}
	else
	{
		exit_status = atoi(args[1]);
		exit(exit_status);
	}
}
