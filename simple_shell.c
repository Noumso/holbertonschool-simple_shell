#include "shell.h"

/**
 * main - Point d'entrée pour le shell simple
 *
 * Retourne: Toujours 0 (Succès)
 */
int main(void)
{
    char buffer[TAILLE_BUFFER];
    ssize_t n_lu;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);
        n_lu = lire_entree(buffer, TAILLE_BUFFER);
        if (n_lu == -1)
        {
            perror("read");
            continue;
        }
        if (n_lu == 0)
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }
        if (buffer[n_lu - 1] == '\n')
            buffer[n_lu - 1] = '\0';
        if (buffer[0] == '\0')
            continue;
        creer_processus(buffer);
    }
    return (0);
}
