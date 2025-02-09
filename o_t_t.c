#include "push_swap.h"

void sort_2(stack_t *a)
{
    if (a->head->i > a->head->next->i)
        swap(a);
}

void sort_3(stack_t *a) {
    int top = a->head->i;
    int mid = a->head->next->i;
    int bot = a->tail->i;

    if (top > mid && mid < bot && top < bot)
        swap(a);
    else if (top > mid && mid > bot) 
    { 
        swap(a);
        reverse_rotate(a); 
    }
    else if (top > mid && mid < bot)
        rotate(a);
    else if (top < mid && mid > bot && top < bot) 
    {
        reverse_rotate(a); 
        swap(a); 
    }
    else if (top < mid && mid > bot)
            reverse_rotate(a);
}

void sort_5(stack_t *a, stack_t *b)
{
    int i;
     i = 0 ;
     while(i < 2)
     {
        while (a->head->i != get_min(a))
            rotate(a);
        push(a, b);
        i++;
     }
    sort_3(a);
    while (b->head) 
        push(b, a);
    if (a->head->i > a->head->next->i) 
        swap(a);
}