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
void execute_command(char *command);
char *find_command_in_path(char *command);
int command_exists(char *command);
void handle_exit(void);
int tokenize_command(char *command, char **argv);
char *resolve_command_path(char *command);
void execute_fork(char *resolved_path, char **argv);
void print_environment(void);
void print_env(void);
char *get_env_var(const char *name);
#endif /* SHELL_H *gg=G*/
