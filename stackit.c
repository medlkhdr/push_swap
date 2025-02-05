#include "push_swap.h"

stack_t	*fill_stack(int *arr, int k)
{
	node_t	*a;
	stack_t	*s;
	int		i;
	node_t	*tmp;

	a = malloc(sizeof(node_t));
	s = malloc(sizeof(stack_t));
	s->head = a;
	i = 0;
	tmp = a;
	while (i < k)
	{
		tmp->i = arr[i];
		if (i == k - 1)
		{
			tmp->next = NULL;
			s->tail = tmp;
		}
		else
		{
			tmp->next = malloc(sizeof(node_t));
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (s);
}

void	free_stack(stack_t *stack)
{
	node_t	*tmp;
	node_t	*a;

	a = stack->head;
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	free(stack);
}
stack_t	*initialize_stack(void)
{
	stack_t	*b;

	b = malloc(sizeof(stack_t));
	b->head = b->tail = NULL;
	return (b);
}
void	afficher_stack(stack_t *a)
{
	node_t *b;
	b = a->head;
	while (b)
	{
		printf("%d->", b->i);
		b = b->next;
	}
	printf("NULL\n");
}