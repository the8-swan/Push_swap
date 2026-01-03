/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:10:10 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 16:28:14 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	assign_index(t_stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i < size)
		{
			if (a->num == arr[i])
			{
				a->index = i;
				break ;
			}
			i++;
		}
		a = a->next;
	}
}

void	update_position(t_stack *a)
{
	int	size;
	int	i;

	size = stack_size(a);
	i = 0;
	while (i < size)
	{
		a->position = i;
		i++;
		a = a-> next;
	}
}

void	push_to_b(t_stack	**a, t_stack **b,	int c)
{
	int	pushed;
	int	bign;

	pushed = 0;
	bign = c - 3;
	while (pushed < c - 3)
	{
		if ((*a)->index <= 2)
			ft_rotate(a, NULL);
		else if (((*a)->index > 2 && (*a)->index < c / 2) && bign > c / 2)
			ft_rotate(a, NULL);
		else
		{
			ft_push(a, b, 'b');
			pushed++ ;
			bign--;
		}
	}
}

t_stack	*before_lastnode(t_stack	*s)
{
	t_stack	*last_node;

	while ((s->next)->next)
		s = s->next;
	last_node = s->next;
	s->next = NULL;
	return (last_node);
}
