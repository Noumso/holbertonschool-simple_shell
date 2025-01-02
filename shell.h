#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#define TAILLE_BUFFER 1024
extern char **environ;

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
ssize_t lire_entree(char *buffer, size_t taille);
void creer_processus(char *buffer);
char **toknelize(char *buffer);
char *chercher_commande(char *commande);
#endif

