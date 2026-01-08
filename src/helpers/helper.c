/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:35:23 by obakri            #+#    #+#             */
/*   Updated: 2026/01/08 20:49:10 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ror(t_stack **a, t_stack **b, int costa, int costb)
{
	while (costa > 0)
	{
		ft_rotate(a, NULL);
		(costa)--;
	}
	while (costa < 0)
	{
		ft_rrotate(a, NULL);
		(costa)++;
	}
	while (costb > 0)
	{
		ft_rotate(NULL, b);
		(costb)--;
	}
	while (costb < 0)
	{
		ft_rrotate(NULL, b);
		(costb)++;
	}
}
