# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sboukiou <your@mail.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/09 13:57:32 by sboukiou          #+#    #+#              #
#    Updated: 2025/04/16 18:36:34 by sboukiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
RM=rm -f
CFLAGS=-Wall -Werror -Wextra -pthread
NAME=philo

SOURCES=main.c parser.c
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
