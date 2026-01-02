/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:38:33 by obakri            #+#    #+#             */
/*   Updated: 2026/01/01 22:03:10 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_two(stack *a)
{
	if (a->num > (a->next)->num)
		ft_swap(a, NULL);
}

static stack *find_min_cost(stack *b)
{
	stack *cheapest;
	int sum;

	cheapest = NULL;
	sum = INT_MAX;
	while (b)
	{
		if (ft_abs(b->costa) + ft_abs(b->costb) < sum)
		{
			sum = ft_abs(b->costa) + ft_abs(b->costb);
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

static void move_to_a(stack **a, stack **b, stack *cheapest)
{
	int costa;
	int costb;

	if (!b || !*b || !cheapest)
		return;
	costa = cheapest->costa;
	costb = cheapest->costb;
	while (costa < 0 && costb < 0)
	{
		ft_rrotate(a, b);
		(costa)++;
		(costb)++;
	}
	while (costa > 0 && costb > 0)
	{
		ft_rotate(a, b);
		(costa)--;
		(costb)--;
	}
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
	ft_push(a, b, 'a');
}

void positional_sort(stack **a, stack **b, int c)
{
	stack *tmp;
	stack *cheapest;
	int i;

	i = 0;
	while (i < c)
	{
		tmp = *b;
		 	update_position(*a);
		 	update_position(*b);
		while (tmp)
		 	{
		 		calculate_costa(*a, tmp);
		 		tmp->costb = calculate_costb(*b, tmp);
		 		tmp = tmp->next;
		 	}
		 	tmp = *b;
		 	cheapest = find_min_cost(tmp);
		 	move_to_a(a, b, cheapest);
		i++;
	}
}

void push_swap(int *arr, int c)
{
	stack *a;
	stack *b;
	int i;

	i = 0;
	a = create_stack(arr, c);
	b = NULL;
	if (is_sorted(a))
		return;
	if (c == 2)
	{
		sort_two(a);
		return;
	}
	quick_sort(arr, 0, c - 1);
	assign_index(a, arr, c);
	push_to_b(&a, &b, c);
	sort_three(&a);
	positional_sort(&a, &b, c - 3);
	 rotate_to_position(&a);
	// printf("*****************************");
	/*free_list(&a);
	free_list(&b);
	free(arr);*/
	 stack *aa = a;
	 while(aa){
	 	printf("%d",aa->num);
	 	aa = aa->next;
	 }

}
