#include "push_swap.h"
void message()
{
	write(2,"Error", 5);
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
    if (size == 2) 
		sort_2(stacka);
    else if (size == 3) 
		sort_3(stacka);
    else if (size <= 5) 
		sort_5(stacka, stackb);
    else
		printf("baqi aahsbi ");
	free_stack(stacka);
	free_stack(stackb);
	free(ar);
	return (0);
}
