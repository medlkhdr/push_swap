CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c stackit.c utils.c swap.c push.c rotate.c reverse_rotate.c sort_three_two.c sort_five.c parse.c parse1.c parse2.c sort_alot.c 
HEADER = push_swap.h
NAME = push_swap
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "maked push_swap"

%.o: %.c
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
