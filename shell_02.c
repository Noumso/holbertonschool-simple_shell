#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "shell.h"

void display_prompt(void);
char *read_command(void);
char **parse_command(char *command);
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
 * parse_command - Sépare la commande et ses arguments
 * @command: la ligne de commande entrée par l'utilisateur
 * Return: tableau de chaînes contenant la commande et ses arguments
 */
char **parse_command(char *command)
{
	char **argv;
	char *token;
	int i = 0;

	argv = malloc(sizeof(char *) * (strlen(command) / 2 + 1));

	if (!argv)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " ");
	while (token != NULL)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	return (argv);
}

/**
 * execute_command - Exécute une commande via execve
 * @command: ligne de commande entrée par l'utilisateur
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char **argv;
	struct stat st;

	argv = parse_command(command);

	if (stat(argv[0], &st) == 0 && (st.st_mode & S_IXUSR))
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(argv);
			return;
		}

		if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(argv[0]);
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
		fprintf(stderr, "%s: command not found\n", argv[0]);
	}

	free(argv);
}

