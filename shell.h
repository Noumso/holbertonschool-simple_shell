#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Function prototypes */
void execute_command(char *command, int count, char *nom);
char *find_command_in_path(char *command);
int command_exists(char *command);
void my_exit(char *nom, int count, char *line);
int tokenize_command(char *command, char **argv);
char *resolve_command_path(char *command);
void execute_fork(char *resolved_path, char **argv);
void print_environment(void);
void print_env(void);
int _isdigit(int c);
#endif /* SHELL_H */
