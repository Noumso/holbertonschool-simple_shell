#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h" /* Inclure le fichier d'en-tête */

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);

/**
 * main - simple UNIX command line interpreter
 * Return: 0 on success, or exit code on failure
 */
int main(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = read_command();
		if (!command)
			break;
		execute_command(command);
		free(command);
	}
	return (0);
}

/**
 * display_prompt - Affiche le prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_command - Lit une commande entrée par l'utilisateur
 * Return: pointeur vers la commande (ou NULL si Ctrl+D)
 */
char *read_command(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';
	return (line);
}

/**
 * execute_command - Exécute une commande via execve
 * @command: ligne de commande entrée par l'utilisateur
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char *argv[2];
	struct stat st;
	if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		argv[0] = command;
		argv[1] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return;
		}

		if (pid == 0)
		{
			if (execve(command, argv, environ) == -1)
			{
				perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", command);
	}
}
