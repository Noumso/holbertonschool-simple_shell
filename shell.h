#ifndef SHELL_H
#define SHELL_H

extern char **environ;

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

#endif

