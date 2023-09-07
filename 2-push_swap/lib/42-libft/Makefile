# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 11:03:52 by liguyon           #+#    #+#              #
#    Updated: 2023/09/06 14:34:59 by liguyon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output
NAME		:= libft.a

# Includes
INC_DIR		:= .

# Sources
SRC_DIR		:= src
SRC_		:= stdlib/ft_calloc.c \
		   stdlib/ft_realloc.c \
		   stdlib/ft_atoi.c \
		   stdlib/ft_atol.c \
		   stdlib/ft_itoa.c \
		   string/ft_bzero.c \
		   string/ft_memchr.c \
		   string/ft_memcmp.c \
		   string/ft_memcpy.c \
		   string/ft_memmove.c \
		   string/ft_memset.c \
		   string/ft_split.c \
		   string/ft_strchr.c \
		   string/ft_strdup.c \
		   string/ft_striteri.c \
		   string/ft_strjoin.c \
		   string/ft_strlcat.c \
		   string/ft_strlcpy.c \
		   string/ft_strlen.c \
		   string/ft_strmapi.c \
		   string/ft_strcmp.c \
		   string/ft_strncmp.c \
		   string/ft_strnstr.c \
		   string/ft_strrchr.c \
		   string/ft_strrev.c \
		   string/ft_strtok.c \
		   string/ft_strtrim.c \
		   string/ft_substr.c \
		   ctype/ft_isalnum.c \
		   ctype/ft_isalpha.c \
		   ctype/ft_isascii.c \
		   ctype/ft_isdigit.c \
		   ctype/ft_isspace.c \
		   ctype/ft_isprint.c \
		   ctype/ft_tolower.c \
		   ctype/ft_toupper.c \
		   stdio/ft_putchar_fd.c \
		   stdio/ft_putendl_fd.c \
		   stdio/ft_putnbr_fd.c \
		   stdio/ft_putstr_fd.c \
		   stdio/ft_printf_hex.c \
		   stdio/ft_printf_ptr.c \
		   stdio/ft_printf_uint.c \
		   stdio/ft_printf.c \
		   datastruct/linked-list/ft_lstnew.c \
		   datastruct/linked-list/ft_lstadd_front.c \
		   datastruct/linked-list/ft_lstsize.c \
		   datastruct/linked-list/ft_lstlast.c \
		   datastruct/linked-list/ft_lstadd_back.c \
		   datastruct/linked-list/ft_lstdelone.c \
		   datastruct/linked-list/ft_lstclear.c \
		   datastruct/linked-list/ft_lstiter.c \
		   datastruct/linked-list/ft_lstmap.c \
		   logger/logger.c \

SRC			:= $(addprefix $(SRC_DIR)/, $(SRC_))

# Objects
OBJ_DIR		:= .build
OBJ			:= $(addprefix $(OBJ_DIR)/, $(SRC_:.c=.o))

# Compiler
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -I $(INC_DIR)

# Archive
AR			:= ar rcs

# Targets
$(NAME):	$(OBJ)
		$(AR) $@ $^
		ranlib $@

all:	$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ_DIR)

fclean:	clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
