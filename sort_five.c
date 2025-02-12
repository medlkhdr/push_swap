#include "push_swap.h"

static void first(stack_t *a , stack_t *b)
{
    if(a->head->i == get_min(a))
        pb(a, b);
    else if(a->head->next->i == get_min(a))
    {
        sa(a);
        pb(a,b);
    } else if(a->head->next->next->i == get_min(a))
    {
        ra(a);
        ra(a);
        pb(a, b);
    }
    else if(a->head->next->next->next->i == get_min(a))
    {
        rra(a);
        rra(a);
        pb(a, b);
    }
    else if(a->head->next->next->next->next->i == get_min(a))
    {
        rra(a);
        pb(a, b);
    }
}
static void second(stack_t *a , stack_t *b)
{
    if(a->head->i == get_min(a))
        pb(a, b);
    else if(a->head->next->i == get_min(a))
    {
        sa(a);
        pb(a,b);
    } else if(a->head->next->next->i == get_min(a))
    {
        ra(a);
        ra(a);
        pb(a, b);
    }
    else if(a->head->next->next->next->i == get_min(a))
    {
        rra(a);
        pb(a, b);
    }
}
void sort_5(stack_t *a , stack_t *b )
{
    first(a, b);
    second(a,b);
    if(b->head->i < b->head->next->i)
        sb(b);
    sort_3(a);
    pa(a, b);
    pa(a,b);
}