#include "push_swap.h"

void push(stack_t *from, stack_t *to)
{
    if (!from || !from->head)
        return;
    node_t *top = from->head;
    from->head = top->next;
    if (from->head)
        from->head->prev = NULL;
    else
        from->tail = NULL;
    top->next = to->head;
    if (to->head)
        to->head->prev = top;
    else
        to->tail = top;
    to->head = top;
    top->prev = NULL;
}

void pa(stack_t *a , stack_t *b)
{
    push(b, a);
    write(1 , "pa\n" , 3);
}

void pb(stack_t *a, stack_t *b)
{
    push(a , b);
    write(1, "pb\n", 3);
}
