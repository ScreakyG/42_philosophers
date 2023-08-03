NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -lpthread

### SRCS FILES ###

SRCS_DIR = src/
SRCS_FILES = main.c check_argv.c utils.c init.c exit.c threads.c eat.c getters.c setters.c sleep.c think.c supervisor.c getters2.c setters2.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
SRCS_OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAME)

clean: 
	rm -rf $(SRCS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re