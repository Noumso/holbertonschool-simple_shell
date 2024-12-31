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
char *get_command_path(char *command);
void execute_command(char *command);
int is_exit_command(char *command);

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

		if (is_exit_command(command))
		{
			free(command);
			exit(0);
		}

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
 * Return: pointeur vers la commande ou NULL si Ctrl+D est pressé
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
 * get_command_path - Recherche le chemin complet de la commande
 * @command: la commande entrée par l'utilisateur
 * Return: le chemin complet si trouvé, sinon NULL
 */
char *get_command_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path, *cmd_path;
	struct stat st;

	if (command[0] == '/' || command[0] == '.')
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return (command);
	}
	else
	{
		path = strtok(path_env, ":");
		while (path != NULL)
		{
			cmd_path = malloc(strlen(path) + strlen(command) + 2);
			if (!cmd_path)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(cmd_path, path);
			strcat(cmd_path, "/");
			strcat(cmd_path, command);

			if (stat(cmd_path, &st) == 0 && (st.st_mode & S_IXUSR))
				return (cmd_path);

			free(cmd_path);
			path = strtok(NULL, ":");
		}
	}
	return (NULL);
}

/**
 * execute_command - Exécute la commande via execve
 * @command: la commande entrée par l'utilisateur
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char **argv;
	char *command_path;

	argv = parse_command(command);

	command_path = get_command_path(argv[0]);

	if (command_path)
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
			if (execve(command_path, argv, environ) == -1)
			{
				perror(command_path);
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

/**
 * is_exit_command - Vérifie si la commande est 'exit'
 * @command: la commande entrée par l'utilisateur
 * Return: 1 si la commande est 'exit', 0 sinon
 */
int is_exit_command(char *command)
{
	return (strcmp(command, "exit") == 0);
}

