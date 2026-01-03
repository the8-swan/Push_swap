/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:45:31 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 15:52:38 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid(char *ptr)
{
	int	i;

	i = 0;
	if (i == 0 && ((ptr[i] == '-' || ptr[i] == '+') && ptr[i + 1]))
		i++;
	while (ptr[i] && ft_isdigit(ptr[i]))
		i++;
	if (ptr[i] == '\0')
		return (i);
	else
		return (0);
}

int	digits_counter(char **ptr)
{
	int	c;

	c = 0;
	while (ptr[c] != NULL)
		c++;
	return (c);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static int	is_unique(int value, int *arr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (value == arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	fill_arr(int *arr, char ***ptr)
{
	int	i;
	int	in;
	int	z;

	in = 0;
	z = 0;
	i = 0;
	while (ptr[z])
	{
		while (ptr[z][i])
		{
			if (!is_valid(ptr[z][i]))
				return (write(1, "Error\n", 6), -1);
			arr[in] = ft_atoi(ptr[z][i]);
			if (arr[in] > INT_MAX || arr[in] < INT_MIN)
				return (write(1, "Error\n", 6), -1);
			if (!is_unique(arr[in], arr, in))
				return (write(1, "Error\n", 6), -1);
			i++;
			in++;
		}
		i = 0;
		z++;
	}
	return (in);
}
