#include "shell.h"

/**
 * execute_command - Executes a given command.
 * @command: The command to execute.
 *
 * Description: Forks a new process and executes the given command
 * in the child process using execve. The parent process waits
 * for the child to finish execution. If the command is invalid
 * or inaccessible, an error message is printed.
 */
void execute_command(char *command)
{
	pid_t pid;
	char *argv[2]; /* Argument array for execve */

	/* Prepare arguments */
	argv[0] = command; /* Path to the command */
	argv[1] = NULL;    /* End of arguments */

	/* Fork a new process */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) /* Child process */
	{
		if (execve(command, argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else /* Parent process */
	{
		wait(NULL); /* Wait for the child process to finish */
	}
}
