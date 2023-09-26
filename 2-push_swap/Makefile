##############
#
# Compiler
#
##############
CC	= clang-15
CFLAGS	= -Wall -Wextra -Werror -I$(LIBDIR)/$(LIBFTDIR)
CLFLAGS	= -L$(LIBDIR)/$(LIBFTDIR) -lft

##############
#
# Project files
#
##############
SRCDIR	= src
OBJDIR	= build
OUTDIR	= target

OBJ	= $(SRC:.c=.o)
EXE	= push_swap
NAME = $(EXE)
SRC	= main.c \
	stack.c \
	stack_methods.c \
	stack_ops1.c \
	stack_ops2.c \
	stack_ops3.c \
	stack_sort1.c \
	stack_sort2.c \
	stack_sort3.c \
	check_args.c \
	utils.c \

SRC_BONUS = checker_main.c \
	stack.c \
	stack_methods.c \
	stack_ops1.c \
	stack_ops2.c \
	stack_ops3.c \
	check_args.c \
	utils.c \
	get_next_line.c

EXE_BONUS = checker
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

#
# Debug
#
DBGDIR	= debug
DBGCFLAGS	= -g3 -O0 -DDEBUG
DBGOBJ	= $(addprefix $(OUTDIR)/$(DBGDIR)/$(OBJDIR)/, $(OBJ))
DBGEXE	= $(OUTDIR)/$(DBGDIR)/$(EXE)
#
# Release
#
RELDIR	= release
RELCFLAGS	= -O3
RELOBJ	= $(addprefix $(OUTDIR)/$(RELDIR)/$(OBJDIR)/, $(OBJ))
RELEXE	= $(OUTDIR)/$(RELDIR)/$(EXE)
#
# Bonus
#
RELOBJ_BONUS	= $(addprefix $(OUTDIR)/$(RELDIR)/$(OBJDIR)/, $(OBJ_BONUS))
RELEXE_BONUS	= $(OUTDIR)/$(RELDIR)/$(EXE_BONUS)

##############
#
# Libraries
#
##############
LIBDIR	= lib
LIBFTDIR	= 42-libft
LIBFT	= libft.a


##############
#
# Build
#
##############
.PHONY:	all release debug install run clean fclean re bonus testers

$(NAME):	all

all:	release install

release:	$(LIBFT) $(RELEXE)
	
debug:	$(LIBFT) $(DBGEXE)

install:
	@cp $(RELEXE) .

run: debug
	valgrind --leak-check=full $(OUTDIR)/$(DBGDIR)/$(EXE) $(ARGS)

bonus: $(LIBFT) $(RELEXE_BONUS)
	@cp $(RELEXE_BONUS) .

clean:
	rm -rf $(OUTDIR)/$(DBGDIR)/$(OBJDIR)
	rm -rf $(OUTDIR)/$(RELDIR)/$(OBJDIR)
	@make -C $(LIBDIR)/$(LIBFTDIR) clean

fclean:
	rm -rf $(OUTDIR)
	rm -f $(EXE)
	@make -C $(LIBDIR)/$(LIBFTDIR) fclean

re:	fclean all

testers: bonus
	@rm -rf push_swap_visualizer \
		&& rm -f ./visualizer \
		&& git clone https://github.com/o-reo/push_swap_visualizer.git
	@mkdir -p push_swap_visualizer/build \
		&& cd push_swap_visualizer/build \
		&& cmake .. && make && cd ../../ \
		&& cp push_swap_visualizer/build/bin/visualizer .
	@rm -rf push_swap_tester && rm -f ./complexity \
		&& git clone https://github.com/SimonCROS/push_swap_tester.git
	@make -C push_swap_tester fr && cp push_swap_tester/complexity .

#
# project srcs build
#
$(DBGEXE):	$(DBGOBJ)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -o $@ $(DBGOBJ) $(CLFLAGS)

$(OUTDIR)/$(DBGDIR)/$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -o $@ -c $<

$(RELEXE): $(RELOBJ)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $@ $(RELOBJ) $(CLFLAGS)

$(RELEXE_BONUS): $(RELOBJ_BONUS)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $@ $(RELOBJ_BONUS) $(CLFLAGS)

$(OUTDIR)/$(RELDIR)/$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(RELCFLAGS) -o $@ -c $<

#
# libs build
#
$(LIBFT):
	@make -sC $(LIBDIR)/$(LIBFTDIR)
