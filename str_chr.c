#include "shell.h"

/**
 * _strchr - Locate the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: A pointer to the first occurrence of the character c the string s
 * or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);

	return (NULL);
}

/**
 * _malloc - Fonction personnalisée pour allouer de la mémoire
 * @size: Taille de la mémoire à allouer en octets
 *
 * Return: Pointeur vers la mémoire allouée
 */
void *_malloc(size_t size)
{
	void *ptr = malloc(size);

	if (ptr == NULL)
	{
		exitenv("exit 1");
	}
	return (ptr);
}
