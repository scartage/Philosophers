# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 20:53:35 by scartage          #+#    #+#              #
#    Updated: 2023/03/19 18:21:09 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
#CFLAGS = -Wall -Werror -Wextra -pthread -g
RM = rm -f

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -pthread -g

INCLUDES = inc/philo.h

SRCS = main.c utils.c check_args.c init.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

vpath %.c src
.SECONDEXPANSION:

$(OBJ_DIR)/%.o: %.c $(INCLUDES) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

all: make_dir  $(NAME)

make_dir:
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

