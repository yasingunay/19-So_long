# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygunay <ygunay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 11:07:21 by ygunay            #+#    #+#              #
#    Updated: 2022/11/17 20:20:58 by ygunay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS =  ./gnl/get_next_line_utils.c\
		./gnl/get_next_line.c\
		./srcs/main.c\
		./srcs/map_read.c\
		./srcs/init_game.c\
		./srcs/utils.c\
		./srcs/moves.c\
		./srcs/images.c\
		./srcs/map_check.c\
		./libft/ft_split.c\
		./libft/ft_strdup.c\
		./libft/ft_calloc.c\
		./libft/ft_bzero.c\
		./printf/ft_print_hexa.c\
		./printf/ft_print_ptr.c\
		./printf/ft_print_unsigned.c\
		./printf/ft_printf_utils.c\
		./printf/ft_printf.c\
		
		

OBJS = $(SRCS:.c=.o)																	# trasnforms all the ".c" files into ".o" (objects)


all:	$(NAME)																			# will execute NAME rule

$(NAME) : $(OBJS)
		 @echo $(CURSIVE)$(GRAY) "		-Compiling $(NAME)..." $(NONE)
		 $(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
		 @echo $(CURSIVE)$(GRAY) "		-Compiled" $(NONE)
		 @echo "$(GREEN)$(NAME) created!$(DEFAULT)"
		 
clean:																					# remove all .o
	@echo $(CURSIVE)$(GRAY) "		-Removing object files..." $(NONE)
	$(RM) $(OBJS)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean																			# force remove NAME
	@echo $(CURSIVE)$(GRAY) "		-Removing $(NAME)..." $(NONE)
	$(RM) $(NAME)
	@echo "$(YELLOW)so_long deleted!$(DEFAULT)"
	
re: fclean all																			# rule to recompile MAKEFILE (will remove everything and allows to recompile again)


leaks:		${NAME}																		# adds valgrind to check system leaks
			valgrind --leak-check=full ./$(NAME)
			@echo $(BBlue)No Leaks Detected$(Color_Off);

.PHONY: all clean fclean re 															# in phony section we need to include all used rules
	
	
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
NONE='\033[0m'
GREEN1='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
