/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:16:10 by obakri            #+#    #+#             */
/*   Updated: 2026/01/02 16:19:27 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

stack	*create_node(int n)
{
	stack	*new;

	new = malloc(sizeof(stack));
	if (!new)
		return (NULL);
	new->num = n;
	new->next = NULL;
	return (new);
}

stack	*last_node(stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back(stack **head, stack *new)
{
	stack	*last;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = last_node(*head);
	last->next = new;
}

stack	*create_stack(int *arr, int c)
{
	int		i;
	stack	*head;
	stack	*node;

	i = 0;
	head = NULL;
	while (i < c)
	{
		node = create_node(arr[i]);
		if (!node)
			return (NULL);
		add_back(&head, node);
		i++;
	}
	return (head);
}

void	add_front(stack **lst, stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}
