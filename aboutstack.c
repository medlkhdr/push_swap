#include "push_swap.h"

stack_t fill_stack_a(int *arr , int k)
{
    stack_t *s = malloc(sizeof(stack_t));
    node_t*a = malloc(sizeof(node_t));
    if(!a)
    {
        write(1 , "filed to allocated\n", 20);
        free(arr);
        exit(1);
    }
    int i = 0 ; 
    s->head = a;
    a->prev = NULL;
    while(i < k)
    {
        a->i = arr[k];
        if(i == k)
        {
            a->next = NULL;
        }
        else 
        {
            a->next = malloc(sizeof(node_t));
            a->next->prev = a;
            a = a->next;
        }
        k++;
    }
    s->tail = a;
    return s;
}
void writestack(stack_t *a )
{
    node_t *b ; 
    b = a->head;
    while(b)
    {
        printf("%d->",b->i);
        b = b->next;
    }
    printf("NULL");
}