# include "push_swap.h"

//this are just function of th e operations that we gonna need in the algorithme of pushswap , so first i'm gonna create the operations then we gonna stay with algo 

void sa(stack_t *a)
{
    if(a->head && a->head->next)
    {
        node_t *first = a->head; 
        node_t *second = a->head->next;
        int swap = first->i ;
        first->i = second->i ; 
        second->i = swap ;
    }
}

void sb(stack_t *b )
{
    if(b->head && b->head->next)
    {
        node_t *first = b->head;
        node_t *second = b->head->next;
        int swap ;
        swap = first->i ;
        first->i = second->i ;
        second->i = swap ;
    }
}

void ss(stack_t *a , stack_t *b)
{
    sb(b);
    sa(a);
}

void pa(stack_t *a, stack_t *b)
{
    if (a->head && b)
    {
        node_t *new_top_to_b = malloc(sizeof(node_t));
        if (!new_top_to_b)
        {
            write(2, "failed to allocate!\n", 20);
            exit(1);
        }

        new_top_to_b->i = a->head->i;
        new_top_to_b->prev = NULL;

        node_t *ad = a->head;
        a->head = a->head->next;

        if (a->head)
            a->head->prev = NULL;

        free(ad);

        new_top_to_b->next = b->head;
        b->head = new_top_to_b;
    }
}

void pb(stack_t *b  , stack_t *a)
{
    pa(b ,a);
}

void ra(stack_t *a)
{
    if (a->head && a->head->next)
    {
        node_t *first = a->head;
        a->head = a->head->next;
        a->head->prev = NULL;

        node_t *last = first;
        while (last->next)
            last = last->next;

        last->next = first;
        first->prev = last;
        first->next = NULL;
    }
}

void rb(stack_t *b)
{
    ra(b);
}

void rr(stack_t *a, stack_t *b)
{
    ra(a);
    rb(b);
}

void rra(stack_t *a)
{
    if (a->head && a->head->next)
    {
        node_t *last = a->tail;
        node_t *second_last = last->prev;

        second_last->next = NULL;
        last->prev = NULL;

        last->next = a->head;
        a->head->prev = last;
        a->head = last;

        a->tail = second_last;
    }
}

void rrb(stack_t *b)
{
    rra(b);
}

void rrr(stack_t *a, stack_t *b)
{
    rra(a);
    rrb(b);
}