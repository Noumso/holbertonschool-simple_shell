#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char buffer[TAILLE_BUFFER]; /* Buffer to store the user input */
    ssize_t n_read;           /* Number of characters read */
    pid_t pid;                /* Process ID for fork */
    int status;               /* Status for waitpid */
    struct stat st;           /* For checking if the command is executable */

    while (1)
    {
        /* Display the prompt */
        write(STDOUT_FILENO, "$ ", 2);

        /* Read user input */
        n_read = read(STDIN_FILENO, buffer, TAILLE_BUFFER - 1);
        if (n_read == -1) /* Error reading input */
        {
            perror("read");
            continue;
        }
        if (n_read == 0) /* End of file (Ctrl+D) */
        {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        /* Null-terminate the input and remove trailing newline */
        buffer[n_read] = '\0';
        if (buffer[n_read - 1] == '\n')
            buffer[n_read - 1] = '\0';

        /* Skip empty input */
        if (buffer[0] == '\0')
            continue;

        /* Check if the command exists and is executable */
        if (stat(buffer, &st) != 0 || !(st.st_mode & S_IXUSR))
        {
            write(STDOUT_FILENO, "Error: Command not found\n", 25);
            continue;
        }

        /* Create a child process to execute the command */
        pid = fork();
        if (pid == -1) /* Error during fork */
        {
            perror("fork");
            continue;
        }
        if (pid == 0) /* Child process */
        {
            char *args[2];
	    args[0] = buffer; 
	    args[1] = NULL;
            if (execve(buffer, args, NULL) == -1) /* Execute the command */
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else /* Parent process */
        {
            waitpid(pid, &status, 0); /* Wait for the child to finish */
        }
    }

    return (0);
}

