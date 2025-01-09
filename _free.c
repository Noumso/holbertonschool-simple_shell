#include "shell.h"

/**
 * my_malloc - Fonction personnalisée pour allouer de la mémoire
 * @size: Taille de la mémoire à allouer en octets
 *
 * Return: Pointeur vers la mémoire allouée
 */
void *my_malloc(size_t size)
{

	void *ptr = _malloc(size);


	if (ptr == NULL)
	{
		exit (1);
	}
	return (ptr);
}

/**
 * my_free - Fonction personnalisée pour libérer de la mémoire
 * @ptr: Pointeur vers la mémoire à libérer
 *
 * Cette fonction libère la mémoire allouée et s'assure
 * libération en vérifiant que le pointeur est valide avant de le libérer.
 */
void my_free(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

