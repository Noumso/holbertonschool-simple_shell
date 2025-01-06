#include "shell.h"

/**
 * exitenv - Gère les commandes spéciales et tokenize une ligne de commande
 * @buffer: Ligne de commande à analyser
 *
 * Cette fonction traite les commandes spéciales comme "exit" et "env".
 * Si aucune commande spéciale n'est trouvée, elle tokenize la ligne
 * pour créer un tableau d'arguments.
 *
 * Return: Un tableau d'arguments si la commande n'est pas spéciale,
 *         NULL si une commande spéciale est éxécutée ou si une erreur survient.
 */
char **exitenv(char *buffer)
{
	char **args;
    /* Commande spéciale : exit */
    if (_strncmp(buffer, "exit", 5) == 0)
    {
        exit(0); /* Quitte le programme */
    }

    /* Commande spéciale : env */
    if (_strncmp(buffer, "env", 3) == 0)
    {
        executer_env(); /* Affiche les variables d'environnement */
        return (NULL);
    }

    /* Tokenisation de la ligne */
    args = tknelize(buffer);
    if (!args || !args[0])
    {
        free(args); /* Libère la mémoire si la tokenisation échoue */
        return (NULL);
    }

    return (args); /* Retourne le tableau d'arguments */
}

