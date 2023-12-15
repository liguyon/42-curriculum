##############
#
# Compiler
#
##############
CPPC	= c++
CPPFLAGS	= -Wall -Wextra -Werror \
	-std=c++98 \
	-I$(INCDIR) \
	-g \
	# -O2 \

CPPLFLAGS	= 


##############
#
# Project files
#
##############
SRCDIR	= src
OBJDIR	= build
INCDIR	= src

OBJ	= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
NAME = violence
SRC	= main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp \


##############
#
# Build
#
##############

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME): $(OBJ)
	$(CPPC) $(CPPFLAGS) -o $(NAME) $^ $(CPPLFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#
# project srcs build
#
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CPPC) $(CPPFLAGS) -o $@ -c $<
