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
NAME		= libft.a

# Sources
SRC		= ft_toupper.c \
		  ft_tolower.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strrev.c \

SRC_BONUS	= ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c \

# Compiler
CC		= cc
CFLAGS		= -Wall -Wextra -Werror

# Archive
AR		= ar
ARFLAGS		= -rc

OBJ		= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)



$(NAME):	$(OBJ)
		$(AR) $(ARFLAGS) $@ $^

all:		$(NAME)

bonus:		$(OBJ) $(OBJ_BONUS)
		ar -rc $(NAME) $^

%.o:		%.c
		$(CC) $(CFLAGS) -o $@ -c $< -I.

clean:
		rm -f $(OBJ) $(OBJ_BONUS)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: 	all bonus clean fclean re
