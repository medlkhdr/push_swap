#include "push_swap.h"

void rotate(stack_t *stack)
{
    if (!stack || !stack->head || !stack->head->next)
        return;
    node_t *first = stack->head;
    stack->head = first->next;
    stack->head->prev = NULL;
    stack->tail->next = first;
    first->prev = stack->tail;
    first->next = NULL;
    stack->tail = first;
}

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

