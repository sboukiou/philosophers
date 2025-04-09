CC=cc -o
CFLAGS=-Wall -Werror -Wextra -pthread
NAME=philo
SOURCES=main.c args_checker.c
OBJS=$(SOURCES:%.c=%.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(NAME) $(CFLAGS) $(SOURCES)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: fclean all
