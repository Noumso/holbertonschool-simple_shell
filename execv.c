#include "shell.h"

/**
 * execute_command - Executes a given command.
 * @command: The command to execute
 * @count: le nombre d'execution.
 * @nom: nom de programme.
 *
 * Description: This function creates a child process, uses `execve` to
 * execute the command, and handles the command's arguments.
 * It also handles the special case for the `env` command
 * to print environment variables.
 */
void execute_command(char *command, int count, char *nom)
{
	char *argv[1024]; /* Array for the command and its arguments */
	char *resolved_path;

	if (command == NULL || *command == '\0')
	{
		return;
	}

	/* Tokenize the command to get the arguments */
	if (tokenize_command(command, argv) == 0)
	{
		return;
	}

	/* Special case for the `env` command */
	if (strcmp(argv[0], "env") == 0)
	{
		print_environment();
		return;
	}

	/* Resolve the path of the command */
	resolved_path = resolve_command_path(argv[0]);
	if (resolved_path == NULL)
	{
		printf("%s: %d: %s: not found\n", nom, count, argv[0]);
		return;
	}

	/* Fork and execute the command */
	execute_fork(resolved_path, argv);
	free(resolved_path);
}

/**
 * tokenize_command - Tokenizes the input command into arguments.
 * @command: The command string to tokenize.
 * @argv: The array to store the arguments.
 *
 * Return: The number of arguments parsed.
 */
int tokenize_command(char *command, char **argv)
{
	int i = 0;
	char *token;

	token = strtok(command, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	return (i);
}

/**
 * resolve_command_path - Resolves the full path of the command.
 * @command: The command name to resolve.
 *
 * Return: The resolved path of the command or NULL if not found.
 */
char *resolve_command_path(char *command)
{
	return (find_command_in_path(command));
	/* Ensure find_command_in_path is correctly implemented*/
}

/**
 * execute_fork - Forks the process and executes the command.
 * @resolved_path: The resolved path of the command to execute.
 * @argv: The array of arguments.
 *
 * Description: This function forks a child process and uses `execve` to
 * execute the command in the child process. It handles errors and waits for
 * the child process to finish.
 */
void execute_fork(char *resolved_path, char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(resolved_path, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
/**
 * print_environment - Prints the environment variables.
 *
 * Description: This function prints all the environment variables
 * to the standard output, one per line.
 */
void print_environment(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
