# Simple Shell Project
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=700&size=40&pause=1000&center=true&width=700&height=62&lines=Simple + Shell + Project)](https://git.io/typing-svg)

![](https://www.commentcoder.com/static/bd7bd17f9fccb49b563e643f73bc87b3/b17f8/c-Shell.jpg)
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
