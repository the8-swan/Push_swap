/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:16:10 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 16:27:06 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = n;
	new->next = NULL;
	return (new);
}

t_stack	*last_node(t_stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	add_back(t_stack **head, t_stack *new)
{
	t_stack	*last;

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

t_stack	*create_stack(int *arr, int c)
{
	int		i;
	t_stack	*head;
	t_stack	*node;

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

void	add_front(t_stack **lst, t_stack *new)
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
