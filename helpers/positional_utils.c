/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positional_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:06:16 by obakri            #+#    #+#             */
/*   Updated: 2026/01/02 17:11:32 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	helper(stack *a, int *index, int *position)
{
	*index = a->index;
	*position = a->position;
}

int	find_target(stack *a, stack *tmp)
{
	int		index;
	int		position;
	stack	*current;

	index = INT_MAX;
	position = -1;
	current = a;
	 while (current)
	 {
	 	if (current->index > tmp->index && current->index < index)
	 		helper(current, &index, &position);
	 	current = current->next;
	 }
	 if (position < 0)
	 {
	 	while (a)
	 	{
	 		if (a->index < index)
	 			helper(a, &index, &position);
	 		a = a->next;
	 	}
	 }
	return (position);
}

void	calculate_costa(stack *a, stack *tmp)
{
	int	a_size;

	a_size = stack_size(a);
	tmp->target = find_target(a, tmp);
	if (tmp->target <= a_size / 2)
		tmp->costa = tmp->target;
	else
		tmp->costa = -(a_size - tmp->target);
}

int	calculate_costb(stack *b, stack *tmp)
{
	int	current_position;
	int	b_size;

	current_position = tmp->position;
	b_size = stack_size(b);
	if (tmp->position <= b_size / 2)
		return (tmp->position);
	else
		return (-(b_size - tmp->position));
}

void	rotate_to_position(stack **a)
{
	int		size_a;
	int		i;
	stack	*tmp;

	size_a = stack_size(*a);
	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == 0)
			break ;
		tmp = tmp -> next;
		i++;
	}
	if (i > size_a / 2)
		i = - (size_a - i);
	while (i > 0)
	{
		ft_rotate(a, NULL);
		i--;
	}
	while (i < 0)
	{
		ft_rrotate(a, NULL);
		i++;
	}
}
