# NOTE: to use with valgrind --> valgrind --tool=helgrind [Program_name] [arguments]
# -fsanitize=thread
#  -g (Debug info)
CC=cc
RM=rm -f
CFLAGS=-Wall -Werror -Wextra -pthread -g
NAME=philo
TEST=test
TEST_SRC=test.c

SOURCES=main.c parser.c time.c cleanup.c init.c philos.c getters_setters.c monitor.c actions.c
OBJS=$(SOURCES:%.c=%.o)

DEPS_SOURCES=./Deps/atoi.c ./Deps/isdigit.c ./Deps/strlen.c ./Deps/printers.c
DEPS_OBJS=$(DEPS_SOURCES:%.c=%.o)

OBJS_ALL=$(OBJS) $(DEPS_OBJS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS_ALL)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS_ALL)

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)
re: fclean all

$(TEST): $(TEST_SRC)
	$(CC) $(CFLAGS) $(TEST_SRC) -o $(TEST)
