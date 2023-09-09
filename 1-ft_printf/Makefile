# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 14:19:52 by liguyon           #+#    #+#              #
#    Updated: 2023/04/26 15:36:41 by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		= libftprintf.a

# Sources
SRC		= ft_printf.c \
		  ft_printf_uint.c \
		  ft_printf_hex.c \
		  ft_printf_ptr.c

# Includes
INCLUDE		= ft_printf.h

# Libraries
LIBFT_DIR 	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Compiler
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CPFLAGS		= -I. -I$(LIBFT_DIR)
CLFLAGS		= $(LIBFT)

# Archive
AR		= ar
ARFLAGS		= -rc

OBJ		= $(subst .c,.o,$(SRC))

$(NAME):	$(OBJ)
		$(AR) $(ARFLAGS) $@ $?

all:		$(NAME)

$(LIBFT):
		$(MAKE) all -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)

%.o:		%.c $(LIBFT)
		$(CC) $(CFLAGS) $(CPFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)

re:		fclean all

compile:
		$(CC) $(CFLAGS) -I$(LIBFT_DIR) main.c $(NAME) -g3 -o printf

dbg:
		valgrind -s --leak-check=full ./printf


.PHONY:		all clean fclean re compile dbg
