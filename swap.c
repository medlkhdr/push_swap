#include "push_swap.h"

void swap(stack_t *stack)
{
    if (!stack || !stack->head || !stack->head->next)
        return;
    node_t *first = stack->head;
    node_t *second = first->next;
    first->next = second->next;
    if (first->next)
        first->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->head = second;
    if (stack->tail == second)
        stack->tail = first;
}

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

