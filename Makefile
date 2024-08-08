NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIB_DIR = lib/libft
LIBFT = $(LIB_DIR)/libft.a
SRCS_DIR = srcs/push_swap/
# it tells the linker to add ./lib/libft to its search path for libraries and  to link against a library named 'libft'.
#INCLUDE = -L $(LIB_DIR) -lft

SRCS_O = operations_combs.c operations_rotate.c operations_swap_push.c process_args.c \
		push_swap_main.c sort_ascending.c sort_caculate_steps_assit.c sort_caculate_steps.c \
		util_basic.c util_stacklist1.c util_stacklist2_find.c
SRCS = $(addprefix $(SRCS_DIR),$(SRCS_O))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) -fPIC $(OBJS) $(LIBFT) -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "Compiling: $<"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIB_DIR) clean
	@echo "push_swap objects are cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo "All executable files are cleaned!"

re: fclean all

.PHONY: all clean fclean re
