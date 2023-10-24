##############
#
# Compiler
#
##############
CC	= cc
CFLAGS	= -Wall -Wextra -Werror \
	-I$(LIBDIR)/$(LIBFTDIR) \
	-I$(LIBDIR)/$(LIBMLXDIR) \
	-O3 \
	-gdwarf-2

CLFLAGS	= -lXext -lX11

##############
#
# Project files
#
##############
SRCDIR	= src
OBJDIR	= build

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
NAME = so_long
SRC	= main.c \
	  utils.c \
	  timer.c \
	  graphics.c \
	  graphics_render.c \
	  graphics_draw.c \
	  inputs.c \
	  sprite.c \
	  load.c \
	  render.c \
	  parse.c \
	  parse1.c


##############
#
# Libraries
#
##############
LIBDIR	= lib
LIBFTDIR	= 42-libft
LIBFT	= $(LIBDIR)/$(LIBFTDIR)/libft.a
LIBMLXDIR	= minilibx-linux
LIBMLX	= $(LIBDIR)/$(LIBMLXDIR)/libmlx.a

##############
#
# Build
#
##############

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ) $(LIBMLX) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(CLFLAGS)

clean:
	rm -rf $(OBJDIR)
	@make -sC $(LIBDIR)/$(LIBFTDIR) clean
	@make -sC $(LIBDIR)/$(LIBMLXDIR) clean

fclean:	clean
	rm -f $(NAME)
	@make -sC $(LIBDIR)/$(LIBFTDIR) fclean

re:	fclean all

#
# project srcs build
#
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

#
# libs build
#
$(LIBFT):
	@make -sC $(LIBDIR)/$(LIBFTDIR)

$(LIBMLX):
	@make -sC $(LIBDIR)/$(LIBMLXDIR)
