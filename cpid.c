#include "shell.h"

/**
 * creer_processus - Crée un processus enfant et exécute une commande
 * @buffer: Commande à exécuter
 *
 * Retourne: Rien.
 */
void creer_processus(char *buffer)
{
        pid_t pid;
        int statut;

        pid = fork();
        if (pid == -1)
        {
                perror("Erreur fork");
                return;
        }

        if (pid == 0)
        {
                char **args;
                args = toknelize(buffer);
                if (execve(args[0], args, environ) == -1)
                {
                        perror(args[0]);
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                waitpid(pid, &statut, 0);
        }
}

