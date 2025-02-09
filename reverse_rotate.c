#include "push_swap.h"

void rra(stack_t *a)
{
    reverse_rotate(a);
    write(1 , "rra\n", 4);
}

void rrb(stack_t *b)
{
    reverse_rotate(b);
    write(1 , "rrb\n", 4);
}

void rrr(stack_t *a , stack_t *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1,"rrr\n", 4);
}
