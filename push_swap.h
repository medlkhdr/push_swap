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


int get_chunk_size(int total_size);
void push_chunk_to_b(stack_t *a, stack_t *b, int chunk_min, int chunk_max);
int find_next_in_chunk(stack_t *stack, int chunk_min, int chunk_max);
void sort_stack_b(stack_t *b);

//operation of stack
void window_sort(stack_t *a, stack_t *b);
void sb(stack_t *b);
void sa(stack_t *a);
void ss(stack_t *a , stack_t *b);
void pb(stack_t *b, stack_t *a);
pa(stack_t *a , stack_t *b);
stack_t				*fill_stack(int *arr, int k);
stack_t				*initialize_stack(void);
void				free_stack(stack_t *stack);
void				afficher_stack(stack_t *a);
void				replace_by_space(char *str);
int stack_size(stack_t *stack);
int get_min(stack_t *stack);
int get_max(stack_t *stack);
void sort_2(stack_t *a);
void sort_3(stack_t *a);
void sort_5(stack_t *a, stack_t *b);
void radix_sort(stack_t *a, stack_t *b);
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
void				reverse_rotate(stack_t *stack);
void				rotate(stack_t *stack);
void				push(stack_t *from, stack_t *to);
void				swap(stack_t *stack);

#endif

