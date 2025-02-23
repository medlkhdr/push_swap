#include "push_swap.h"

void	rotate(stack_t *stack)
{
	node_t	*first;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	stack->head = first->next;
	stack->head->prev = NULL;
	stack->tail->next = first;
	first->prev = stack->tail;
	first->next = NULL;
	stack->tail = first;
}

void	ra(stack_t *a)
{
	rotate(a);
}

void	rb(stack_t *b)
{
	rotate(b);
}

void	rr(stack_t *a, stack_t *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(stack_t *stack)
{
	node_t	*last;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->prev = NULL;
	last->next = stack->head;
	stack->head->prev = last;
	stack->head = last;
}

void	rra(stack_t *a)
{
	reverse_rotate(a);
}

void	rrb(stack_t *b)
{
	reverse_rotate(b);
}

void	rrr(stack_t *a, stack_t *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	swap(stack_t *stack)
{
	node_t	*first;
	node_t	*second;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->head = second;
	if (stack->tail == second)
		stack->tail = first;
}

void	sa(stack_t *a)
{
	swap(a);
}

void	sb(stack_t *b)
{
	swap(b);
}

void	ss(stack_t *a, stack_t *b)
{
	swap(a);
	swap(b);
}

void	push(stack_t *from, stack_t *to)
{
	node_t	*top;

	if (!from || !from->head)
		return ;
	top = from->head;
	from->head = top->next;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	top->next = to->head;
	if (to->head)
		to->head->prev = top;
	else
		to->tail = top;
	to->head = top;
	top->prev = NULL;
}

void	pa(stack_t *a, stack_t *b)
{
	push(b, a);
}

void	pb(stack_t *a, stack_t *b)
{
	push(a, b);
}