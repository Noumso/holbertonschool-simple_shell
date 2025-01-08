#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: Always 0.
 *
 * Description: This function continuously reads input commands
 * from the user (or from a file in non-interactive mode), and
 * executes them using the execute_command function.
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Interactive mode */
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1) /* End of file (Ctrl+D) */
			break;

		/* Remove newline character */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Skip empty lines */
		if (*line == '\0')
			continue;

		/* Check for built-in command "exit" */
		if (strcmp(line, "exit") == 0)
			break;

		/* Execute the command */
		execute_command(line);
	}

	free(line);
	return (0);
}
