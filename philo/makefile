NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
INCLUDES	= -I./includes
# LIBS		= -L./lib/libft -lft -lreadline

SRC_DIR		= .
OBJ_DIR		= obj

SRC_FILES	= philosophers.c \
				sample.c \
				get_current_time.c \
				input_checker.c \
				set_simulation.c \
				ft_atol.c

SRCS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -g3
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ Philo compiled successfully!$(RESET)"

unit-tests:
	@$(MAKE) -C ./tests

norminette:
	@norminette ./*.c ./*.h

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C ./tests
	@echo "$(RED)Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -rf ./test/test_report.log
	@$(MAKE) fclean -C ./tests
	@echo "$(RED)Executable removed$(RESET)"

sanitize: CFLAGS += -fsanitize=address
sanitize: re
	@echo "$(GREEN)✓ Philo compiled with AddressSanitizer!$(RESET)"

tester: CFLAGS += -DTESTER
tester: re
	@echo "$(GREEN)✓ Shelly compiled for tester mode!$(RESET)"

val:
	@valgrind \
			--leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			--trace-children=yes \
			--track-fds=yes \
			--trace-children-skip='/bin/,/sbin/,/usr/bin/*' \
			./$(NAME) 30 200 300 400 600
# 			--suppressions=shelly.supp ./$(NAME)

re: fclean all

.PHONY: all clean fclean re sanitize tester