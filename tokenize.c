#include "shell.h"

/**
 * tokenize - Divise une chaîne en tokens.
 * @buffer: Ligne de commande à analyser.
 * Return: Tableau de tokens.
 */
char **tokenize(char *buffer)
{
    char **tokens = NULL, *token;
    size_t i = 0, size = 10;

    tokens = malloc(size * sizeof(char *));
    if (!tokens)
        return (NULL);

    token = strtok(buffer, " ");
    while (token)
    {
        tokens[i++] = strdup(token);
        if (i >= size)
        {
            size += 10;
            tokens = realloc(tokens, size * sizeof(char *));
        }
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return (tokens);
}

