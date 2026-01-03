/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:48:26 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 15:45:20 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_helper(t_stack **a)
{
	t_stack	*next_node;
	t_stack	*first_node;

	next_node = (*a)->next;
	first_node = *a;
	first_node->next = NULL;
	*a = next_node;
	add_back(a, first_node);
}

void	rrotate_helper(t_stack **a)
{
	t_stack	*last_node;

	last_node = before_lastnode(*a);
	last_node->next = *a;
	*a = last_node;
}

void	swap_helper(t_stack *head)
{
	t_stack	*next;
	int		val;
	int		index;

	next = head->next;
	val = next->num;
	index = next->index;
	next->num = head->num;
	next->index = head->index;
	head->num = val;
	head->index = index;
}

void	push_helper(t_stack **a, t_stack **b)
{
	t_stack	*first_node;

	first_node = *b;
	*b = first_node -> next;
	first_node->next = NULL;
	add_front(a, first_node);
}
