#ifndef PUSH_SWAP_H 
#define PUSH_SWAP_H
#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>

typedef struct node_s 
{
	int i ; 
	struct node_s *next ;
	struct node_s *prev ;
} node_t;

typedef struct stack_s
{
	node_t *tail ; // i add to get the last node and take to the top , is simplifying my work with rotate function , to just take the tail , and make in the top  
	node_t *head;
} stack_t;
#endif 
