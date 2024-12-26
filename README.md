# Simple Shell Project

## Description
This project is a simple Unix shell implementation written in C. It provides a command-line interface where users can execute commands, handle files, and manage processes.

## Features
- Execute commands with arguments
- Handle built-in commands like `exit` and `env`
- Manage the PATH variable to locate executables
- Support for input/output redirection and pipes
- Handle signals like `Ctrl+C`

## How to Compile
To compile the shell, use:
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
