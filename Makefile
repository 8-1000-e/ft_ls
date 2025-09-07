# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emile <emile@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 11:41:12 by edubois-          #+#    #+#              #
#    Updated: 2025/09/07 21:53:18 by emile            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	ft_ls

PRINTF_DIR		:= libft/printf_fd
PRINTF_LIB		:= $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR 		:=	libft/
LIBFT_LIB 		:= $(LIBFT_DIR)/libft.a

SRCS 			=	srcs/main.c\
					srcs/get_flags.c\
					srcs/flags_handler/ls.c\
					srcs/flags_handler/flag_utils.c\
					srcs/flags_handler/sort.c\

OBJS 			:= $(SRCS:.c=.o)

CC 				:= @cc

FLAGS 			:= -Wall -Wextra -Werror -g

.SILENT:

all: $(NAME) clean

$(NAME):	$(LIBFT_LIB) $(PRINTF_LIB) $(OBJS)
	@echo "Compilation de $(NAME)"
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	clear

$(PRINTF_LIB):
	@echo "Compilation de printf_fd..." 
	make -s -C $(PRINTF_DIR)

$(LIBFT_LIB):
	@echo "Compilation de libft..." 
	make -s -C  $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "Suppresion des objets..." 
	make clean -s -C  $(LIBFT_DIR)
	make clean -s -C  $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	@echo "Suppresion des executables..." 
	make fclean -s -C  $(LIBFT_DIR)
	make fclean -s -C  $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
