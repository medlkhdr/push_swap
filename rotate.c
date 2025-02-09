#include "push_swap.h"

void ra(stack_t *a)
{
    rotate(a);
    write(1, "ra\n", 3);
}


void rb(stack_t *b)
{
    rotate(b);
    write(1 ,"rb\n" , 3 );
}

void rr(stack_t *a , stack_t *b)
{
    rotate(a);
    rotate(b);
    write(1 , "rr\n", 3);
}

