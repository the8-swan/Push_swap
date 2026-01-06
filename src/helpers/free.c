/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:51:59 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 18:24:23 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_list(t_stack **st)
{
	t_stack	*next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

void	free_ptr(char ***ptr, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		while (ptr[i][j])
		{
			free(ptr[i][j]);
			j++;
		}
		free(ptr[i]);
		j = 0;
		i++;
	}
	free(ptr);
	free(arr);
}
