#include "get_next_line/get_next_line.h"
#include "push_swap.h"

int compare(char *f, char *op)
{
    int i = 0;
    while (f[i])
    {
        if (f[i] != op[i])
            return 0;
        i++;
    }
    return (f[i] == op[i]);
}

int khdma(char *f, stack_t *a, stack_t *b)
{
    if (compare(f, "ra\n"))
        ra(a);
    else if (compare(f, "rra\n"))
        rra(a);
    else if (compare(f, "rb\n"))
        rb(b);
    else if (compare(f, "rrb\n"))
        rrb(b);
    else if (compare(f, "rr\n"))
        rr(a, b);
    else if (compare(f, "rrr\n"))
        rrr(a, b);
    else if (compare(f, "pa\n"))
        pa(a, b);
    else if (compare(f, "pb\n"))
        pb(a, b);
    else if (compare(f, "sa\n"))
        sa(a);
    else if (compare(f, "sb\n"))
        sb(b);
    else if (compare(f, "ss\n"))
        ss(a, b);
    else
        return 0;
    return 1;
}

int sorted_check(stack_t *a, stack_t *b)
{
    node_t *t;

    if (!b->head)
    {
        t = a->head;
        while (t && t->next)
        {
            if (t->i > t->next->i)
                return 0;
            t = t->next;
        }
        return 1;
    }
    return 0;
}

void clean_exit(stack_t *stacka, stack_t *stackb, char *f)
{
	if(stacka)
		free_stack(stacka);
    if(stackb)
		free_stack(stackb);
    if (f)
        free(f);
    write(1, "Error", 5);
    exit(1);
}

int main(int ac, char **av)
{
    int k;
    int *ar;
    stack_t *stacka;
    stack_t *stackb;
    char *f;

    if (ac < 2)
        return 0;
    if (av[1][0] == '\0')
    {
        write(1, "Error", 5);
        exit(1);
    }
    ar = parse_input(ac, av, &k);
    is_here_dup(ar, k);
    stackb = initialize_stack();
    if (!stackb)
    {
        free(ar);
        write(2, "Error", 5);
        exit(1);
    }
    stacka = fill_stack(ar, k);
    if (!stacka)
    {
        free(ar);
        free(stackb);
        write(2, "Error", 5);
        exit(1);
    }
    free(ar);
    while (1)
    {
		f  = get_next_line(0);
		if(!f)
			break;
        if (khdma(f, stacka, stackb) == 0)
            clean_exit(stacka, stackb, f);
        free(f);
    }
    if (sorted_check(stacka, stackb))
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(stacka);
    free_stack(stackb);
    return 0;
}
