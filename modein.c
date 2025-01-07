#include "shell.h"

/**
 * mode_interactif - Gère l'exécution en mode interactif.
 * Affiche une invite ("$"), lit les commandes utilisateur,
 * et les traite en conséquence.
 */
void mode_interactif(void)
{
    char *buffer;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);
        buffer = _getline();
        if (buffer == NULL)
        {
            perror("Erreur de lecture");
            continue;
        }
        if (_strncmp(buffer, "exit", 4) == 0 &&
            (buffer[4] == '\0' || buffer[4] == ' '))
        {
            free(buffer);
            break;
        }
        if (_strncmp(buffer, "env", 3) == 0 &&
            (buffer[3] == '\0' || buffer[3] == ' '))
        {
            executer_env();
            free(buffer);
            continue;
        }
        if (buffer[0] == '\0')
        {
            free(buffer);
            continue;
        }
        if (traiter_ligne(buffer) == NULL)
        {
            write(STDERR_FILENO, "Erreur lors du traitement de la commande\n", 42);
        }
        free(buffer);
    }
}
