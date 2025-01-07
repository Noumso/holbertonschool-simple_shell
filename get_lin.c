#include "shell.h"

/**
 * _getline - Lit une ligne depuis stdin en allouant dynamiquement la mémoire
 * Return: Chaîne contenant la ligne lue, ou NULL en cas d'erreur
 */

char *_getline()
{
	int i = 0, buffsize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
		return (NULL);

	while (c != '\n' && c != EOF)
	{
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i++] = c;
		if (i >= buffsize)
		{
			buffsize += BUFSIZE;
			buff = _realloc(buff, buffsize - BUFSIZE, buffsize);
			if (buff == NULL)
				return (NULL);
		}
	}
	buff[i] = '\0';
	hashtag_handle(buff);
	if (buff[0] == '\n')
	{
		free(buff);
		return ("\0");
	}

	return (buff);
}

/**
 * hashtag_handle - Supprime tout ce qui suit un `#` dans une chaîne
 * @buff: Chaîne d'entrée
 * Return: void
 */
void hashtag_handle(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}

