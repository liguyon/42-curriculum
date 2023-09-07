# Output
NAME		:= minitalk

NAME_CLIENT	:= client

NAME_SERVER	:= server

# Includes
INC_DIR		:= include

# Sources
SRC_DIR		:= src

SRC_CLIENT	:= client/client.c \
			   client/utils.c

SRC_SERVER	:= server/server.c \
			   server/utils.c

# Objects
OBJ_DIR		:= build

OBJ_CLIENT	:= $(addprefix $(OBJ_DIR)/, $(SRC_CLIENT:.c=.o))

OBJ_SERVER	:= $(addprefix $(OBJ_DIR)/, $(SRC_SERVER:.c=.o))

# Libraries
LIB_DIR		:= lib

LIBFT_DIR	:= $(LIB_DIR)/42-libft

LIBFT		:= libft.a

# Compiler
CC		:= cc

CFLAGS		:= -Wall -Wextra -Werror -g3 -I $(INC_DIR) -I $(LIBFT_DIR)/include

CLFLAGS		:= -L$(LIBFT_DIR) -lft

# Targets

$(NAME):	$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJ_CLIENT)
		$(MAKE) -C $(LIBFT_DIR) all
		$(CC) $(CFLAGS) $^ -o $(NAME_CLIENT) $(CLFLAGS)

$(NAME_SERVER):	$(OBJ_SERVER)
		$(MAKE) -C $(LIBFT_DIR) all
		$(CC) $(CFLAGS) $^ -o $(NAME_SERVER) -L ./$(LIBFT_DIR) $(CLFLAGS)

$(LIBFT):	
		$(MAKE) -C $(LIBFT_DIR) all

all:		$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
		rm -f $(NAME) $(NAME_CLIENT) $(NAME_SERVER)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: 		fclean all

.PHONY: 	all clean fclean re
