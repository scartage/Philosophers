# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 15:03:58 by scartage          #+#    #+#              #
#    Updated: 2023/05/15 17:21:41 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	:= \033[32m
NAME	:= philo_bonus
CC		:= GCC
RM		:= rm -rf

CFLAGS		= -Wall -Werror -Wextra -fsanitize=address -MMD -pthread -g
INCLUDES	= inc/philo_bonus.h

SRCS		= main_bonus.c check_args.c init.c utils_bonus.c create_bonus.c \
				clean.c routine_bonus.c prints_bonus.c

OBJ_DIR 	= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS		= $(SRCS:.c=.d))

vpath	%.c src

$(OBJ_DIR)/%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)
all: make_dir $(NAME)

make_dir:
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(INCLUDES)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN) $(NAME) compiled!!"

clean: 
		$(RM) $(OBJ_DIR)
		@echo "$(GREEN) $(NAME) cleaned"

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re