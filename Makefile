# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 11:07:21 by ygunay            #+#    #+#              #
#    Updated: 2022/10/17 11:07:24 by ygunay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = test.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Werror -Wextra



all:	$(NAME)

$(NAME) : $(OBJS)
		 $(CC) $(CFLAGS) test.c -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		 @echo "$(GREEN)$(NAME) created!$(DEFAULT)"
clean:
	$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
	
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m