#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define TAILLE_BUFFER 1024
extern char **environ;

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void creer_processus(char **args);
char **traiter_ligne(char *buffer);
char **tknelize(char *buffer);
char *verifier_commande(char **args);
void executer_env(void);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _atoi(char *s);
void _puts(char *str);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
char *_getenv(char *name);
char *chercher_commande(char *commande);
void mode_interactif(void);
void mode_non_interactif(void);
char *_strchr(const char *s, int c);
char *exitenv(char *buffer);
ssize_t lire_entree(char *buffer);
#endif
