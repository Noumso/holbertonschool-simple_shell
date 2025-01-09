#include "shell.h"

/**
 * write_custom - Fonction personnalisée
 * @fd: Descripteur de fichier où écrire
 * @buf: Pointeur vers les données à écrire (message).
 * @count: Nombre d'octets du message à écrire.
 *
 * Return: Nombre d'octets écrits, ou -1 en cas d'erreur.
 */
ssize_t write_custom(int fd, char *buf, size_t count)
{

	char *prefix = "";
	size_t prefix_len = strlen(prefix);
	ssize_t bytes_written;


	size_t total_len = prefix_len + count;


	char *new_buf = _malloc(total_len);
	if (new_buf == NULL)
	{
		return (-1);
	}


	_memcpy(new_buf, prefix, prefix_len);


	_memcpy(new_buf + prefix_len, buf, count);


	bytes_written = write(fd, new_buf, total_len);


	my_free(new_buf);

	return (bytes_written);
}
