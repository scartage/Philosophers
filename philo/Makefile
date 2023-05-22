# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 18:00:51 by scartage          #+#    #+#              #
#    Updated: 2023/05/22 18:20:37 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN 	:= \033[32m
NC		:= \033[m
NAME 	= philo
CC 		= gcc
RM 		= rm -rf

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -MMD -pthread -g
#CFLAGS	= -Wall -Werror -Wextra -MMD -pthread -g

INCLUDES = inc/philo.h

SRCS 	= main.c check_args.c init.c utils.c create_pthread.c prints.c \
		  ft_eat_sleep_think.c check_finish.c clean.c

OBJ_DIR = obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS	= $(SRCS:.c=.d)

vpath %.c src

$(OBJ_DIR)/%.o: %.c $(INCLUDES) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)
all: make_dir $(NAME)

make_dir:
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(INCLUDES)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) $(NAME) compiled! $(NC)"

clean:
		$(RM) $(OBJ_DIR)
		@echo "$(GREEN) $(NAME) cleaned $(NC)"

fclean: clean
		$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re make_dir

