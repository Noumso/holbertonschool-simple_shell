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
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int count = 0;

	while (1)
	{
		count ++;
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
		if (strncmp(line, "exit", 4) == 0)
		{
			my_exit(argv[0], count ,line);
		continue;
		}

		/* Execute the command */
		execute_command(line);
	}

	free(line);
	return (0);
}
