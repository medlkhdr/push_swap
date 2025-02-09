#include "push_swap.h"

int stack_size(stack_t *stack)
{
    int size = 0;
    node_t *current = stack->head;
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}

int get_min(stack_t *stack)
{
    int min = INT_MAX;
    node_t *current = stack->head;
    while (current)
    {
        if (current->i < min)
            min = current->i;
        current = current->next;
    }
    return min;
}

int get_max(stack_t *stack) 
{
    int max = INT_MIN;
    node_t *current = stack->head;
    while (current)
    {
        if (current->i > max)
            max = current->i;
        current = current->next;
    }
    return max;
}