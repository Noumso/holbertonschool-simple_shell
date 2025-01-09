#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_FUNC_NAME 128
#define MAX_LINE_LEN 1024

// Structure pour stocker les noms de fonctions et leurs comptes
typedef struct {
    char name[MAX_FUNC_NAME];
    int count;
} FunctionCount;

// Ajoute ou met à jour un nom de fonction dans le tableau
void add_or_update_function(FunctionCount *functions, int *func_count, const char *name) {
    for (int i = 0; i < *func_count; i++) {
        if (strcmp(functions[i].name, name) == 0) {
            functions[i].count++;
            return;
        }
    }
    // Nouvelle fonction, on l'ajoute
    strncpy(functions[*func_count].name, name, MAX_FUNC_NAME - 1);
    functions[*func_count].count = 1;
    (*func_count)++;
}

// Trie les fonctions par ordre alphabétique
int compare_functions(const void *a, const void *b) {
    return strcmp(((FunctionCount *)a)->name, ((FunctionCount *)b)->name);
}

// Analyse un fichier pour extraire les appels de fonctions
void analyze_file(const char *filename, FunctionCount *functions, int *func_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    char line[MAX_LINE_LEN];
    regex_t regex;
    regcomp(&regex, "\\b([a-zA-Z_][a-zA-Z0-9_]*)\\s*\\(", REG_EXTENDED);

    while (fgets(line, sizeof(line), file)) {
        char *current = line; // Pointeur pour parcourir la ligne
        regmatch_t match[2];
        char func_name[MAX_FUNC_NAME];

        // Recherche des fonctions ligne par ligne
        while (regexec(&regex, current, 2, match, 0) == 0) {
            int len = match[1].rm_eo - match[1].rm_so;
            strncpy(func_name, current + match[1].rm_so, len);
            func_name[len] = '\0';

            // Ajoute ou met à jour la fonction
            add_or_update_function(functions, func_count, func_name);

            // Continue après la correspondance trouvée
            current += match[1].rm_eo;
        }
    }

    regfree(&regex);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier1.c> <fichier2.c> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    FunctionCount functions[1024];
    int func_count = 0;

    // Analyse chaque fichier
    for (int i = 1; i < argc; i++) {
        printf("Analyse du fichier : %s\n", argv[i]);
        analyze_file(argv[i], functions, &func_count);
    }

    // Trie les fonctions par ordre alphabétique
    qsort(functions, func_count, sizeof(FunctionCount), compare_functions);

    // Affiche les résultats
    printf("\nNombre exact d'appels de fonctions (ordre alphabétique) :\n");
    for (int i = 0; i < func_count; i++) {
        printf("%s: %d\n", functions[i].name, functions[i].count);
    }

    return EXIT_SUCCESS;
}

