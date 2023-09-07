# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 11:03:52 by liguyon           #+#    #+#              #
#    Updated: 2023/04/24 21:02:02 by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		:= libft.a

# Includes
INC_DIR		:= include

# Sources
SRC_DIR		:= src
SRC_		:= memory/ft_bzero.c \
		   memory/ft_calloc.c \
		   memory/ft_memblock.c \
		   memory/ft_memchr.c \
		   memory/ft_memcmp.c \
		   memory/ft_memcpy.c \
		   memory/ft_memmove.c \
		   memory/ft_memset.c \
		   memory/ft_realloc.c \
		   string/ft_atoi.c \
		   string/ft_atol.c \
		   string/ft_itoa.c \
		   string/ft_split.c \
		   string/ft_strchr.c \
		   string/ft_strdup.c \
		   string/ft_striteri.c \
		   string/ft_strjoin.c \
		   string/ft_strlcat.c \
		   string/ft_strlcpy.c \
		   string/ft_strlen.c \
		   string/ft_strmapi.c \
		   string/ft_strncmp.c \
		   string/ft_strnstr.c \
		   string/ft_strrchr.c \
		   string/ft_strrev.c \
		   string/ft_strtrim.c \
		   string/ft_substr.c \
		   character/ft_isalnum.c \
		   character/ft_isalpha.c \
		   character/ft_isascii.c \
		   character/ft_isdigit.c \
		   character/ft_isprint.c \
		   character/ft_tolower.c \
		   character/ft_toupper.c \
		   write/ft_print_error.c \
		   write/ft_putchar_fd.c \
		   write/ft_putendl_fd.c \
		   write/ft_putnbr_fd.c \
		   write/ft_putstr_fd.c \
		   linked_list/ft_lstnew.c \
		   linked_list/ft_lstadd_front.c \
		   linked_list/ft_lstsize.c \
		   linked_list/ft_lstlast.c \
		   linked_list/ft_lstadd_back.c \
		   linked_list/ft_lstdelone.c \
		   linked_list/ft_lstclear.c \
		   linked_list/ft_lstiter.c \
		   linked_list/ft_lstmap.c \
		   ft_printf/ft_printf_hex.c \
		   ft_printf/ft_printf_ptr.c \
		   ft_printf/ft_printf_uint.c \
		   ft_printf/ft_printf.c \

SRC		:= $(addprefix $(SRC_DIR)/, $(SRC_))

# Objects
OBJ_DIR		:= build
OBJ		:= $(addprefix $(OBJ_DIR)/, $(SRC_:.c=.o))

# Compiler
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR)

# Archive
AR		:= ar
ARFLAGS		:= -rc

$(NAME):	$(OBJ)
		$(AR) $(ARFLAGS) $@ $^

all:		$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ_DIR) 

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: 	all bonus clean fclean re
