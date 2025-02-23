CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = push_swap.c parsing.c sorting.c stack_operations.c stack_utils.c utils.c big_sort.c
HEADER = push_swap.h
NAME = push_swap
NAME1 = checker
OBJS = $(SRCS:.c=.o)
DIR_GET = get_next_line
HEADER_C  = $(DIR_GET)/get_next_line.h 
SRCS_B = $(DIR_GET)/get_next_line.c $(DIR_GET)/get_next_line_utils.c stack_operations_c.c stack_utils.c parsing_c.c utils.c my_checker.c
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)


bonus: $(NAME1)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "making push_swap..."

$(NAME1):$(OBJS_B) $(HEADER_C) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME1)
	@echo "making checker..."
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJS_B)
	@echo "clean object files"

fclean: clean
	@rm -rf $(NAME) $(NAME1)
	@echo "clean excutables"

re: fclean all
	@echo "remaking"

.PHONY: all clean fclean re
