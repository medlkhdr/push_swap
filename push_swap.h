#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>

typedef struct node_s
{
	int				i;
	struct node_s	*next;
	struct node_s	*prev;
}					node_t;

typedef struct stack_s
{
	node_t			*tail;
	node_t			*head;
}					stack_t;
stack_t				*fill_stack(int *arr, int k);
stack_t				*initialize_stack(void);
void				free_stack(stack_t *stack);
void				afficher_stack(stack_t *a);
void				replace_by_space(char *str);
void				check(char *str);
char				*join(int ac, char **av, size_t size);
void				da7k(char *string, int *i);
size_t				ft_strlen(const char *s);
void				handle_overflow(int *a, char *b);
int					*parse_input(int ac, char **av, int *k);
void				parse_numbers(char *input, int *arr);
int					extract_number(char *input, int *i, int *arr);
void				is_here_dup(int *a, int k);
int					is_sorted(int *a, int k);
void				process_stack(int *ar, int k);

#endif
