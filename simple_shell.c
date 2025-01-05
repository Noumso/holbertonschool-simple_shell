#include "shell.h"

/**
 * main - Point d'entrée principal du programme.
 * Cette fonction détecte si l'exécution doit se faire en mode inta ou non
 * interactif en vérifiant si l'entrée standard est un terminal.
 *
 * Return: Toujours 0 (succès).
 */
int main(void)
{
	if (isatty(STDIN_FILENO)) /* Mode interactif */
	{
		mode_interactif();
	}
	else /* Mode non interactif */
	{
		mode_non_interactif();
	}

	return (0);
}
