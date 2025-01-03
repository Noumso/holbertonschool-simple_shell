#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **tokenize(char *buffer);
void execute_command(char **args, char **env);
int handle_builtins(char **args, char **env);
void afficher_env(char **env);

#endif /* SHELL_H */

