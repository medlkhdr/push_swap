#include "push_swap.h"
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
