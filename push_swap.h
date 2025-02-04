#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H
#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node_s 
{
	int i ; 
	struct node_s *next ;
	struct node_s *prev ;
} node_t;

typedef struct stack_s
{
	node_t *tail ;
	node_t *head;
} stack_t;
stack_t* create_stack(int *arr , int k );
stack_t *initialize_stack(void);
void free_stack(stack_t *stack);
void afficher_stack(stack_t *a);
#endif 
