/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:53:25 by obakri            #+#    #+#             */
/*   Updated: 2026/01/06 09:54:14 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_swap_bonus(t_stack *a, t_stack *b)
{
	if (a && a->next != NULL)
	{
		swap_helper(a);
		if (!b)
			return ;
	}
	if (b && b->next != NULL)
	{
		swap_helper(b);
		if (!a)
			return ;
	}
}

void	ft_rrotate_bonus(t_stack **a, t_stack **b)
{
	if (a != NULL && *a && (*a)->next)
		rrotate_helper(a);
	if (b != NULL && *b && (*b)->next)
		rrotate_helper(b);
}

void	ft_rotate_bonus(t_stack **a, t_stack **b)
{
	if (a != NULL && *a && (*a)->next)
		rotate_helper(a);
	if (b != NULL && *b && (*b)->next)
		rotate_helper(b);
}

void	ft_push_bonus(t_stack **a, t_stack **b, char c)
{
	if (c == 'a' && *b)
		push_helper(a, b);
	else if (c == 'b' && *a)
		push_helper(b, a);
}
