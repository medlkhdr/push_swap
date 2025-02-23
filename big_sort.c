#include "push_swap.h"

int	get_pos_in_range(stack_t *s, int low_val, int high_val)
{
	int		pos;
	node_t	*tmp;

	pos = 0;
	tmp = s->head;
	while (tmp)
	{
		if (tmp->i >= low_val && tmp->i <= high_val)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}
int	nichan(int best_top, int best_bot, int size)
{
	if (best_top == -1 && best_bot == -1)
		return (-1);
	else if (best_top == -1)
		return (best_bot);
	else if (best_bot == -1)
		return (best_top);
	else if (best_top <= (size - best_bot))
		return (best_top);
	else
		return (best_bot);
}
int	get_best_pos_in_range(stack_t *s, int low_val, int high_val)
{
	node_t	*tmp;

	int pos_top, best_top, size, pos_bot, best_bot;
	size = stack_size(s);
	tmp = s->head;
	best_top = -1;
	pos_top = 0;
	while (tmp)
	{
		if (tmp->i >= low_val && tmp->i <= high_val)
		{
			best_top = pos_top;
			break ;
		}
		pos_top++;
		tmp = tmp->next;
	}
	pos_bot = size - 1;
	best_bot = -1;
	tmp = s->tail;
	while (tmp)
	{
		if (tmp->i >= low_val && tmp->i <= high_val)
		{
			best_bot = pos_bot;
			break ;
		}
		pos_bot--;
		tmp = tmp->prev;
	}
	return (nichan(best_top, best_bot, size));
}
void	rotate_to_position(stack_t *stack, int pos, int size, char a)
{
	if (a == 'a')
	{
		if (pos <= size / 2)
		{
			while (pos--)
				ra(stack);
		}
		else
		{
			pos = size - pos;
			while (pos--)
				rra(stack);
		}
	}
	else
	{
		if (pos <= size / 2)
		{
			while (pos--)
				rb(stack);
		}
		else
		{
			pos = size - pos;
			while (pos--)
				rrb(stack);
		}
	}
}

void	push_to_stackb(stack_t *stacka, stack_t *stackb, int *sorted_arr,
		int start, int end, int mid)
{
	int pos, size_a;
	pos = get_best_pos_in_range(stacka, sorted_arr[start], sorted_arr[end]);
	size_a = stack_size(stacka);
	if (pos == -1)
		return ;
	rotate_to_position(stacka, pos, size_a, 'a');
	pb(stacka, stackb);
	if (stackb->head && stackb->head->i <= sorted_arr[mid])
		rb(stackb);
}

void	push_max_to_stacka(stack_t *stacka, stack_t *stackb)
{
	int			max_pos = 0, pos;
	node_t		*tmp;
	int			size_b;
	static int	flag = 0;
	int			max_less_pos;
	int			max_less;
	int			cost_max;
	int			cost_max_less;
	int max; 
	max_pos = 0, pos = 0;
	tmp = stackb->head;
	size_b = stack_size(stackb);
	max = tmp->i;
	while (tmp)
	{
		if (tmp->i > max)
		{
			max = tmp->i;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	pos = 0;
	max_less_pos = 0;
	tmp = stackb->head;
	max_less = tmp->i;
	while (tmp)
	{
		if (tmp->i < max && tmp->i > max_less)
		{
			max_less = tmp->i;
			max_less_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (max_pos <= size_b / 2)
		cost_max = max_pos;
	else
		cost_max = size_b - max_pos;
	if (max_less_pos <= size_b / 2)
		cost_max_less = max_less_pos;
	else
		cost_max_less = size_b - max_less_pos;
	if (!flag && cost_max_less < cost_max)
	{
		rotate_to_position(stackb, max_less_pos, size_b, 'b');
		pa(stacka, stackb);
		flag = 1;
	}
	else
	{
		rotate_to_position(stackb, max_pos, size_b, 'b');
		pa(stacka, stackb);
		if (flag)
			flag = 0;
	}
	if (stacka->head && stacka->head->next
		&& stacka->head->i > stacka->head->next->i)
		sa(stacka);
}

void	push_range_to_stackb(stack_t *stacka, stack_t *stackb, int *sorted_arr,
		int size, int div)
{
	int mid, offset, start, end;
	mid = size / 2 - 1;
	offset = size / div;
	start = mid - offset;
	if (start < 0)
		start = 0;
	end = mid + offset;
	if (end >= size)
		end = size - 1;
	while (stack_size(stacka) > 0)
	{
		push_to_stackb(stacka, stackb, sorted_arr, start, end, mid);
		if (get_best_pos_in_range(stacka, sorted_arr[start], sorted_arr[end]) ==
			-1)
		{
			start = start - offset;
			if (start < 0)
				start = 0;
			end = end + offset;
			if (end >= size)
				end = size - 1;
		}
	}
}

void	big_sort(stack_t *stacka, stack_t *stackb, int *sorted_arr, int size)
{
	int	div;

	if (size < 100)
		div = 5;
	else if (size < 500)
		div = 8;
	else
		div = 16;
	push_range_to_stackb(stacka, stackb, sorted_arr, size, div);
	while (stack_size(stackb) > 0)
		push_max_to_stacka(stacka, stackb);
}
