#include "shell.h"

/**
 * find_command_in_path - Resolves a command to its full path.
 * @command: The command to resolve.
 *
 * Return: A pointer to the resolved path (needs to be freed),
 * or NULL if the command is not found.
 */
char *find_command_in_path(char *command)
{
	char *path, *dir, *full_path;
	struct stat st;

	if (command == NULL)
		return (NULL);

	if (command[0] == '/' || command[0] == '.') /* Absolute or relative path */
	{
		if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
			return (strdup(command));
		return (NULL);
	}

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path = strdup(path); /* Duplicate PATH for strtok */
	dir = strtok(path, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path == NULL)
			break;

		sprintf(full_path, "%s/%s", dir, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
