#include "push_swap.h"

int	stack_size(stack_t *stack)
{
	int		size;
	node_t	*current;

	size = 0;
	current = stack->head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

int	get_min(stack_t *stack)
{
	int		min;
	node_t	*current;

	min = INT_MAX;
	current = stack->head;
	while (current)
	{
		if (current->i < min)
			min = current->i;
		current = current->next;
	}
	return (min);
}

int	get_max(stack_t *stack)
{
	int		max;
	node_t	*current;

	max = INT_MIN;
	current = stack->head;
	while (current)
	{
		if (current->i > max)
			max = current->i;
		current = current->next;
	}
	return (max);
}

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

	if (!stack)
		return ;
	a = stack->head;
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	if(stack)
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
		printf("%d->", b->index);
		b = b->next;
	}
	printf("NULL\n");
}
