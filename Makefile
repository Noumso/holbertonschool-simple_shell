# Name of the executable
NAME = hsh

# Compiler and compilation flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# List of source files
SRCS = simple_shell.c execv.c check.c path.c env.c exit.c

# List of object files (generated from source files)
OBJS = $(SRCS:.c=.o)

# Default target (compiles the program)
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Rule to generate object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Full cleanup (object files + executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Test the environment functionality
env:
	./hsh -c "env"

# Indicate that these targets are not real files
.PHONY: all clean fclean re env

