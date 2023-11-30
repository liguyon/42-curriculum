##############
#
# Compiler
#
##############
CC	= cc
CFLAGS	= -Wall -Wextra -Werror \
	-I$(INCDIR) \
	-g \

CLFLAGS	= -lXext -lX11 -lm

##############
#
# Project files
#
##############
SRCDIR	= src
OBJDIR	= build
INCDIR	= src

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
NAME = philo
SRC	= main.c \


##############
#
# Build
#
##############

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(CLFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#
# project srcs build
#
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<
