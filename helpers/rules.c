#include "../push_swap.h"

void swap(stack *head){
	stack *next = head->next;
	int val = next->num;
	next->num = head->num;
	head->num = val;
}

void ft_swap(stack *a,stack *b)
{
	int c;
	
	c = 0;
	if(a && a->next!= NULL){
		swap(a);
		if(!b){
			write(1,"sa\n",3);
			return;
		}
		c++;
	}
	if(b && b->next!= NULL){
		swap(b);
		if(!a){
			write(1,"sb\n",3);
			return;
		}
		c++;
	}	
	if(c == 2)
		write(1,"ss\n",3);
}
