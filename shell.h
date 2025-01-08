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
void print_env(void);
#endif /* SHELL_H */
