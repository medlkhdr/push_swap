#include "push_swap.h"

void sort_2(stack_t *a)
{
    if (a->head->i > a->head->next->i)
        sa(a);
}

void sort_3(stack_t *a) {
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

void sort_5(stack_t *a, stack_t *b)
{
    int i;
     i = 0 ;
     while(i < 2)
     {
        while (a->head->i != get_min(a))
            ra(a);
        pa(a, b);
        i++;
     }
    sort_3(a);
    while (b->head) 
        pa(b, a);
    if (a->head->i > a->head->next->i) 
        sa(a);
}