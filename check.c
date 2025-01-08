#include "shell.h"

/**
 * command_exists - Vérifie si une commande existe.
 * @command: Le chemin ou le nom de la commande.
 *
 * Return: 1 si la commande existe, 0 sinon.
 */
int command_exists(char *command)
{
	struct stat buffer;

	return (stat(command, &buffer) == 0);
}
