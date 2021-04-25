# ok we're gonna grab a whole bunch of the libft and cub3d and libASM makefilesi think



# can i do this? would it work?
#$(NAME)	=	push_swap \
				checker \

PUSH_SWAP	=	push_swap
CHECKER		=	checker


	# prolly gonna have to change this when i have some files compiled into
	# both, but i can prolly just have another folder for those...

	# so that if i want to put both folders in a srcs folder, it's super easy
	# WOOOOOW This was super helpful, cuz the way i had it setup, it deleted my 
		# checker and push_swap folders along with the executable when i did
		# make re... LOL
DIR_SRCS		=	./srcs/

DIR_CHECKER		=	$(DIR_SRCS)checker/
SRCS_CHECKER	=	checker.c \
					parsing.c \
					create_stack.c \
					swap.c \
					apply_operations.c \
					push.c \
					rotate.c \


DIR_PUSH_SWAP	=	$(DIR_SRCS)push_swap/
SRCS_PUSH_SWAP	=	push_swap.c \


DIR_INC		=	includes/
INCS		=	-I$(DIR_INC)


LIBFT_NAME	=	libft.a
DIR_LIBFT	=	../libft/
DIR_LIBFT_INC	=	$(DIR_LIBFT)includes/
LIBFT_INCS	=	-I$(DIR_LIBFT_INC)

#ALL_LIBS	=	$(DIR_LIBFT)$(LIBFT_NAME)
ALL_LIBS	=	-L$(DIR_LIBFT) -lft
#ALL_LIBS	=	-L$(DIR_LIBFT)

ALL_INCS	=	$(INCS) $(LIBFT_INCS)


CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra


DIR_OBJ		=	./objs/

OBJ_CHECKER	=	$(SRCS_CHECKER:.c=.o)
OBJ_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)

OBJS_CHECKER	=	$(addprefix $(DIR_OBJ),$(OBJ_CHECKER))
OBJS_PUSH_SWAP	=	$(addprefix $(DIR_OBJ),$(OBJ_PUSH_SWAP))



#all: $(CHECKER) $(PUSH_SWAP)

	# just working on Checker for now...
all: $(CHECKER)

$(LIBFT):
	make -C $(DIR_LIBFT) $(LIBFT_NAME)


	### EXECUTABLE CREATION ###


	# don't forget to add more dependancies, like $(LIBFT) and whatever else
	# fairly certain the includes and libs and stuff need to be in both
		# the "Name" rules and the "Obj" rules... I think.

$(CHECKER): $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) $(ALL_INCS) $(ALL_LIBS) $(OBJS_CHECKER) -o $(CHECKER)
	printf "$(_GREEN)\r\33[2K\r$(CHECKER) created  😎\n$(_END)"

$(PUSH_SWAP): $(OBJS_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) $(ALL_INCS) $(ALL_LIBS) $(OBJS_PUSH_SWAP) -o $(PUSH_SWAP)
	printf "$(_GREEN)\r\33[2K\r$(PUSH_SWAP) created  😎\n$(_END)"


	### BINARY CREATION ###

	# may not need to link the libft here... IDK
	# No i do not, just need the .h files of both my program and libft...

$(DIR_OBJ)%.o: $(DIR_CHECKER)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(ALL_INCS) -c $< -o $@
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: $(DIR_PUSH_SWAP)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(ALL_INCS) -c $< -o $@
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"


	### CLEANING ###

clean:
	rm -rf $(DIR_OBJ)
	echo "$(_RED).o Files Deleted  😱$(_END)"

fclean: clean
	rm -rf $(CHECKER) $(PUSH_SWAP)
	echo "$(_RED)$(CHECKER) and $(PUSH_SWAP) Deleted  😱$(_END)"

re: fclean all


	### VARIOUS TESTS, Valgrind, leaks, etc... ###

	# works for just Checker...
	# also, dosen't work on Mac with Big Sur atm... ugh
testl: $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) $(ALL_INCS) $(ALL_LIBS) $(OBJS_CHECKER) -o checker_valgrind -g
	echo "$(_GREEN)\r\33[2K\rValgrind is ready  😎\n$(_END)"

tests: $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) $(ALL_INCS) $(ALL_LIBS) $(OBJS_CHECKER) -o checker_sanitize -g3 -fsanitize=address
	echo "$(_CYAN)Fsanitize Test ready  😬$(_END)"


.PHONY: all clean fclean re

.SILENT:

##################
##    COLORS    ##
##################

_GREY=$ \033[30m
_RED=$ \033[31m
_GREEN=$ \033[32m
_YELLOW=$ \033[33m
_BLUE=$ \033[34m
_PURPLE=$ \033[35m
_CYAN=$ \033[36m
_WHITE=$ \033[37m
_END=$ \033[0m
