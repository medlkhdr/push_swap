#include "push_swap.h"


void sa(stack_t *a)
{
    swap(a);
    write(1 , "sa\n" ,3);
}

void sb(stack_t *b)
{
    swap(b);
    write(1, "sb\n", 3);
}
void ss(stack_t *a , stack_t *b)
{
    swap(a);
    swap(b);
    write(1, "ss\n" , 3);
}

