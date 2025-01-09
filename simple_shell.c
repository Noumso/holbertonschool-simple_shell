#include "shell.h"

/**
 * main - Point d'entrée principal du programme.
 * Cette fonction détecte si l'exécution doit se faire en mode inta ou non
 * interactif en vérifiant si l'entrée standard est un terminal.
 *
 * Return: Toujours 0 (succès).
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	/* Vérifie si stdin est connecté à un terminal pour déterminer le mode */
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
