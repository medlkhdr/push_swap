#include "push_swap.h"
void message()
{
	write(2,"Error", 5);
}
void bubble_sort(int *arr, int size) {
    int i, j, temp;

    i = 0;
    while (i < size - 1) {
        j = 0;
        while (j < size - i - 1) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int *sorted(int *a, int size) {
    int *sorted_arr = (int *)malloc(size * sizeof(int));
    if (!sorted_arr)
        return NULL;

    int i = 0;
    while (i < size) {
        sorted_arr[i] = a[i];
        i++;
    }

    bubble_sort(sorted_arr, size);
    return sorted_arr;
}

void index_it(int *a, stack_t *s, int size)
{
    int *sorted_arr = sorted(a, size);
    if (!sorted_arr)
        return;

    int i = 0;
    node_t *tmp;

    while (i < size)
	{
        tmp = s->head;
        while (tmp)
		{
            if (tmp->i == sorted_arr[i])
			{
                tmp->index = i;
                break;
            }
            tmp = tmp->next;
        }
        i++;
    }
}

int	main(int ac, char **av)
{
	int	k;
	int	*ar;
	stack_t	*stacka;
	stack_t	*stackb;

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
	int size = stack_size(stacka);
	int *sorted_ar = sorted(ar , k);
	index_it(sorted_ar , stacka , k );
    if (size == 2) 
		sort_2(stacka);
    else if (size == 3) 
		sort_3(stacka);
    else if (size <= 5) 
		sort_5(stacka, stackb);
    else
		printf("zbi baqi");
		

	free_stack(stacka);
	free_stack(stackb);
	free(ar);
	return (0);
}
