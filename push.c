#include "push_swap.h"


pa(stack_t *a , stack_t *b)
{
    push(a, b);
    write(1 , "pa\n" , 3);
}

void pb(stack_t *b, stack_t *a)
{
    push(b , a);
    write(1, "pb\n", 3);
}
