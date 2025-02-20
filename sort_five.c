#include "push_swap.h"

static int get_min_index(stack_t *a)
{
    int min = get_min(a);
    int index = 0;
    node_t *current = a->head;
    
    while (current)
    {
        if (current->i == min)
            break;
        index++;
        current = current->next;
    }
    return index;
}

static void smart_rotate(stack_t *a, int target_index)
{
    int size = stack_size(a);
    
    if (target_index <= size / 2)
    {
        while (target_index-- > 0)
            ra(a);
    }
    else
    {
        target_index = size - target_index;
        while (target_index-- > 0)
            rra(a);
    }
}

static void move_min_to_b(stack_t *a, stack_t *b)
{
    int min_index = get_min_index(a);
    smart_rotate(a, min_index);
    pb(a, b);
}

void sort_5(stack_t *a, stack_t *b)
{
    move_min_to_b(a, b);
    move_min_to_b(a, b);

    if (b->head->i < b->head->next->i)
        sb(b);

    sort_3(a);

    pa(a, b);
    pa(a, b);
}