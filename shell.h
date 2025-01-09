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
ssize_t write_custom(int fd, char *buf, size_t count);
void *my_malloc(size_t size);
void my_free(void *ptr);
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void creer_processus(char **args);
char **traiter_ligne(char *buffer, char *nom, int count);
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
void mode_interactif(char *name);
void mode_non_interactif(char *name);
char *_strchr(const char *s, int c);
char *exitenv(char *buffer);
ssize_t lire_entree(char *buffer);
char *_getline();
void hashtag_handle(char *buff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **cmd, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);
void *_malloc(size_t size);
void _perror(char *msg);
#endif
