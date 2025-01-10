#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <errno.h>
#define BUFSIZE 1024
extern char **environ;
#define DELIM " \t\r\n\a"

int _isdigit(int c);
void execute_command(char *command);
void creer_processus(char **args);
char **traiter_ligne(char *buffer, char *nom, int count);
char **tknelize(char *buffer);
char *verifier_commande(char **args);
void executer_env(void);
char *_getenv(char *name);
char *chercher_commande(char *commande);
void mode_interactif(char *name);
void mode_non_interactif(char *name);
char *exitenv(char *buffer);
#endif
