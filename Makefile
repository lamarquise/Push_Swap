
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

NAME		=	push_swap
CHECKER		=	checker

DIR_SRCS		=	./srcs/

DIR_CHECKER		=	$(DIR_SRCS)
SRCS_CHECKER	=	checker_main.c \
					apply_operations.c \
					parse_op_codes.c \

DIR_PUSH_SWAP	=	$(DIR_SRCS)
SRCS_PUSH_SWAP	=	push_swap_main.c \
					pre_sorting.c \
					op_wrappers.c \
					op_wrappers_rotate.c \
					quick_sort.c \
					minisort.c \
					minisort_p2.c \

DIR_BOTH		=	$(DIR_SRCS)
SRCS_BOTH		=	parsing.c \
					create_stack.c \
					op_push.c \
					op_swap.c \
					op_rotate.c \
					utils_both.c \
					split_ints_list.c \
					print_struct_status.c \
					free.c \
					ilist_more.c \
					post_processing.c \

DIR_MINILIB		=	./minilib/
SRCS_MINILIB	=	atoi_funcs.c \
					big_str_funcs.c \
					ft_split.c \
					ft_strjoin.c \
					list_funcs.c \
					nlist_funcs.c \
					nlstdel_n_one.c \
					ilist_funcs.c \
					put_funcs.c \
					str_funcs.c \
					error_funcs.c \
					tab_funcs.c \
					gnl.c \
					gnl_utils.c \

DIR_INC		=	includes/
INCS		=	-I$(DIR_INC)

ALL_INCS	=	$(INCS) -I./minilib/

DIR_OBJ		=	./objs/

OBJ_MINILIB		=	$(SRCS_MINILIB:.c=.o)
OBJ_BOTH		=	$(SRCS_BOTH:.c=.o)
OBJ_CHECKER		=	$(SRCS_CHECKER:.c=.o) $(OBJ_BOTH) $(OBJ_MINILIB)
OBJ_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o) $(OBJ_BOTH) $(OBJ_MINILIB)

OBJS_CHECKER	=	$(addprefix $(DIR_OBJ),$(OBJ_CHECKER))
OBJS_PUSH_SWAP	=	$(addprefix $(DIR_OBJ),$(OBJ_PUSH_SWAP))


	### Rules ###

all: $(NAME)

bonus: $(NAME) $(CHECKER)

	### EXECUTABLE CREATION ###

$(CHECKER): $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(ALL_INCS) $(OBJS_CHECKER) -o $(CHECKER)
	printf "$(_GREEN)\r\33[2K\r$(CHECKER) created  😎\n$(_END)"

$(NAME): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(ALL_INCS) $(OBJS_PUSH_SWAP) -o $(NAME)
	printf "$(_GREEN)\r\33[2K\r$(NAME) created  😎\n$(_END)"


	### BINARY CREATION ###

$(DIR_OBJ)%.o: $(DIR_CHECKER)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(ALL_INCS) -c $< -o $@
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: $(DIR_PUSH_SWAP)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(ALL_INCS) -c $< -o $@
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: $(DIR_BOTH)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(ALL_INCS) -c $< -o $@
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"

$(DIR_OBJ)%.o: $(DIR_MINILIB)%.c
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(ALL_INCS) -c $< -o $@
	printf "$(_CYAN)\r\33[2K\rCompling $@$(_END)"


	### CLEANING ###

clean:
	rm -rf $(DIR_OBJ)
	echo "$(_RED).o Files Deleted  😱$(_END)"

fclean: clean
	rm -rf $(CHECKER) $(NAME)
	echo "$(_RED)$(CHECKER) and $(NAME) Deleted  😱$(_END)"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re testlc testlp testsc testsp

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
