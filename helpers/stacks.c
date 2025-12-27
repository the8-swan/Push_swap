#include "../push_swap.h"


stack	*create_node(int	n)
{
	stack	*new;

	new = malloc(sizeof(stack));
	if(!new)
		return NULL;
	new->num = n;
	new->next = NULL;
	return (new);
}

stack	*last_node(stack	*head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back(stack **head,stack *new)
{
	stack *last;

	if(!head || !new)
		return;
	if(!*head)
	{
		*head = new;
		return ;
	}
	last = last_node(*head);
	last->next = new;
}

stack *create_stack(int *arr,int c){
	int		i;
	stack	*head;

	i = 0;
	head = NULL;
	while (i < c)
	{
		stack	*node = create_node(arr[i]);
		if (!node)
			return (NULL);
		node->position = i;
		if (i <= c/2)
			node->costb = i;
		else
			node -> costb = c - i;
		add_back(&head, node);
		i++;
	}
	return (head);
}


void	add_front(stack **lst, stack *new)
{
	if (!lst || !new || !*lst)
		return ;
	new -> next = *lst;
	*lst = new;
}