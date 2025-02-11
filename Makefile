CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c stackit.c operations.c o_t_t.c utils.c swap.c push.c rotate.c reverse_rotate.c
HEADER = push_swap.h
NAME = push_swap
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "maked push_swap"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@echo "cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "fcleaned"
re: fclean all
	@echo "remaked"
.PHONY: all clean fclean re
