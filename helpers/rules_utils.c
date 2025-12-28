#include "../push_swap.h"


stack	*before_lastnode(stack	*s){
	stack *last_node;

	while((s->next)->next)
		s=s->next;
	last_node = s->next;
	s->next = NULL;
	return last_node;	
}

void	rotate_helper(stack **a)
{
	stack *next_node;
	stack	*first_node;

	next_node = (*a)->next;
	first_node = *a;
	first_node->next = NULL;
	*a = next_node;
	add_back(a,first_node);
}

void	rrotate_helper(stack **a)
{
	stack *last_node;

	last_node = before_lastnode(*a);
	last_node->next = *a;
	*a = last_node;
}


void swap_helper(stack *head)
{
	stack *next;
	int val;

	next = head->next;
	val = next->num;
	next->num = head->num;
	head->num = val;
}


void push_helper(stack **a, stack **b)
{
	stack	*first_node;
	
	first_node = *b;
	*b = first_node -> next;
	first_node->next = NULL;
	add_front(a,first_node);
}
