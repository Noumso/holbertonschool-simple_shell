#include "shell.h"

/**
 * main - Point d'entrée principal du programme.
 * @argc: Cette fonction détecte si l'exécution doit se faire
 * @argv: ven mode inta ou non
 * interactif en vérifiant si l'entrée standard est un terminal.
 *
 * Return: Toujours 0 (succès).
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	if (isatty(STDIN_FILENO))
	{
		mode_interactif(argv[0]);
	}
	else
	{
		mode_non_interactif(argv[0]);
	}
	return (0);
}
