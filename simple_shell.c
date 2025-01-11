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
	char *token;
	int i;
	char *args[10];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		if (*line == '\0')
			continue;
		token = strtok(line, " ");
		i = 0;
		while (token && i < 10)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		if (args[0] != NULL && strcmp(args[0], "exit") == 0)
		{
			handle_exit(args);
			continue;
		}
		execute_command(line);
	}
	free(line);
	return (0);
}
