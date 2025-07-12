NAME=philo
CC=cc
FLAGS=-Wall -Werror -Wextra
RM=rm -f

SOURCES=tokenize.c atoi.c main.c utils.c init.c actions.c routine.c time.c gsetters.c
OBJS=$(SOURCES:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
