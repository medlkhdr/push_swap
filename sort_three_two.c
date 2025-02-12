#include "push_swap.h"

void sort_2(stack_t *a)
{
    if (a->head->i > a->head->next->i)
        sa(a);
}

void sort_3(stack_t *a)
{
    int top = a->head->i;
    int mid = a->head->next->i;
    int bot = a->tail->i;

    if (top > mid && mid < bot && top < bot)
        sa(a);
    else if (top > mid && mid > bot) 
    { 
        sa(a);
        rra(a); 
    }
    else if (top > mid && mid < bot)
        ra(a);
    else if (top < mid && mid > bot && top < bot) 
    {
        ra(a); 
        sa(a); 
    }
    else if (top < mid && mid > bot)
            rra(a);
}