# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 11:07:21 by ygunay            #+#    #+#              #
#    Updated: 2022/11/10 11:58:53 by ygunay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  ./gnl/get_next_line_utils.c\
		./gnl/get_next_line.c\
		./srcs/main.c\
		./srcs/map.c\
		./srcs/hooks.c\
		./srcs/error.c\
		./libft/ft_split.c\
		./libft/ft_strdup.c\

OBJS = $(SRCS:.c=.o)

NAME = so_long

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Werror -Wextra



all:	$(NAME)

$(NAME) : $(OBJS)
		 $(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		 @echo "$(GREEN)$(NAME) created!$(DEFAULT)"
clean:
	$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	$(RM) $(NAME)
	
re: fclean all


leaks:		${NAME}																		# adds valgrind to check system leaks
			valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
			@echo $(BBlue)No Leaks Detected$(Color_Off);

.PHONY: all clean fclean re
	
	
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m