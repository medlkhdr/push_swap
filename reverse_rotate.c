#include "push_swap.h"


void reverse_rotate(stack_t *stack)
{
    if (!stack || !stack->head || !stack->head->next)
        return;
    node_t *last = stack->tail;
    stack->tail = last->prev;
    stack->tail->next = NULL;
    last->prev = NULL;
    last->next = stack->head;
    stack->head->prev = last;
    stack->head = last;
}


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
