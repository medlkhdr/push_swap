#include "push_swap.h"

int	*sorting(int *a, int size)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = malloc(size * sizeof(int));
	if (!sorted_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sorted_arr[i] = a[i];
		i++;
	}
	bubble_sort(sorted_arr, size);
	return (sorted_arr);
}

void	is_sorted_stack(stack_t *a)
{
	node_t	*tmp;

	tmp = a->head;
	while (tmp->next)
	{
		if (tmp->i > tmp->next->i)
		{
			printf("not sorted");
			return ;
		}
		tmp = tmp->next;
	}
	printf("sorted");
}

int	main(int ac, char **av)
{
	int		k;
	int		*ar;
	stack_t	*stacka;
	stack_t	*stackb;
	int		size;
	int		*sorted_ar;

	k = 0;
	if (ac < 2)
		return (0);
	if (av[1] == NULL)
	{
		message();
		exit(1);
	}
	ar = parse_input(ac, av, &k);
	is_here_dup(ar, k);
	stackb = initialize_stack();
	stacka = fill_stack(ar, k);
	size = stack_size(stacka);
	sorted_ar = sorting(ar, k);
	if (size == 2)
		sort_2(stacka);
	else if (size == 3)
		sort_3(stacka);
	else if (size <= 5)
		sort_5(stacka, stackb);
	else
		big_sort(stacka, stackb, sorted_ar, k);
	// is_sorted_stack(stacka);
	// afficher_stack(stackb);
	free_stack(stacka);
	free_stack(stackb);
	free(ar);
	free(sorted_ar);
	return (0);
}
