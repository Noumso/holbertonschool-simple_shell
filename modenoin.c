#include "shell.h"

/**
 * mode_non_interactif - Gère l'exécution en mode non interactif.
 * Lit les commandes ligne par ligne depuis l'entrée standard,
 * les traite, cherche leur chemin complet si besoin, et les exécute.
 */
void mode_non_interactif(void)
{
    char *ligne = NULL;
    size_t taille = 0;
    ssize_t n_lus;
    char **args;
    char *commande;

    while ((n_lus = getline(&ligne, &taille, stdin)) != -1) {
        /* Supprime le caractère de nouvelle ligne */
        if (ligne[n_lus - 1] == '\n') {
            ligne[n_lus - 1] = '\0';
        }
        /* Découpe la ligne en arguments */
        args = traiter_ligne(ligne);
        if (args == NULL) {
            continue; /* Passe à la ligne suivante si aucune commande */
        }
        /* Recherche le chemin complet de la commande */
        commande = chercher_commande(args[0]);
	
        if (commande == NULL) {
            write(STDOUT_FILENO, "Commande introuvable\n", 21);
            free(args);
            continue;
        }

        args[0] = commande; /* Remplace l'argument par le chemin complet */

        /* Exécute la commande dans un processus enfant */
        creer_processus(args);

        free(args); /* Libère la mémoire pour les arguments */
    }

    free(ligne); /* Libère la mémoire allouée pour la ligne */
}
