/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:58:36 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 15:36:23 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(int *a, int *b)
{
	int	c;

	c = *b;
	*b = *a;
	*a = c;
}

static int	partitions(int *arr, int start, int end)
{
	int	i;
	int	pivot;
	int	j;

	pivot = arr[end];
	i = start;
	j = start - 1;
	while (i < end)
	{
		if (arr[i] < pivot)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
		i++;
	}
	swap(&arr[end], &arr[++j]);
	return (j);
}

void	quick_sort(int *arr, int start, int end)
{
	int	p1;

	if (start < end)
	{
		p1 = partitions(arr, start, end);
		quick_sort(arr, start, p1 - 1);
		quick_sort(arr, p1 + 1, end);
	}
}

int	is_sorted(t_stack	*a)
{
	while (a->next)
	{
		if (a->num > (a->next)->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_three(t_stack **a)
{
	t_stack	*head;
	t_stack	*next;

	head = *a;
	next = (*a)->next;
	if (head->index > next->index && head->index > (next->next)->index)
		ft_rotate(a, NULL);
	if (next->index > head->index && next->index > (next->next)->index)
		ft_rrotate(a, NULL);
	if ((*a)->index > ((*a)->next)->index)
		ft_swap(*a, NULL);
}
