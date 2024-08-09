NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIB_DIR = lib/libft
LIBFT = $(LIB_DIR)/libft.a

SRCS_DIR = srcs/push_swap/
SRCS_O = operations_combs.c operations_rotate.c operations_swap_push.c process_args.c \
		push_swap_main.c sort_ascending.c sort_caculate_steps_assit.c sort_caculate_steps.c \
		util_basic.c util_stacklist1.c util_stacklist2_find.c
SRCS = $(addprefix $(SRCS_DIR),$(SRCS_O))
OBJS = $(SRCS:.c=.o)

GNL_DIR = lib/get_next_line
GNL = $(GNL_DIR)/get_next_line.a

SRCS_B_DIR = srcs/checker
SRCS_BONUS_O = checker_main_bonus.c operations_rotate_bonus.c operations_swap_push_bonus.c \
		process_args_bonus.c util_basic_bonus.c
SRCS_BONUS = $(addprefix $(SRCS_B_DIR), $(SRCS_BONUS_O))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -fPIC $(OBJS) $(LIBFT) -o $@

$(BONUS): $(OBJS_BONUS)
	make -C $(LIB_DIR)
	make -C $(GNL_DIR)
	$(CC) $(CFLAGS) -fPIC $(OBJS_BONUS) $(LIBFT) $(GNL) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "Compiling: $<"

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)
	@make clean -C $(GNL)
	@echo "push_swap objects are cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(GNL)
	@echo "All executable files are cleaned!"

re: fclean all

.PHONY: all clean fclean re bonus
