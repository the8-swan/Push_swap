/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:45:31 by obakri            #+#    #+#             */
/*   Updated: 2026/01/08 17:07:21 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *ptr)
{
	int	i;

	i = 0;
	if (i == 0 && ((ptr[i] == '-' || ptr[i] == '+') && ptr[i + 1]))
		i++;
	while (ptr[i] && ft_isdigit(ptr[i]))
		i++;
	if (ptr[i] == '\0' && ft_strl(ptr) <= 11)
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

static int	is_unique(long value, int *arr, int index)
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
	int		i;
	int		in;
	int		z;
	long	number;

	in = 0;
	z = -1;
	i = 0;
	while (ptr[++z])
	{
		while (ptr[z][i])
		{
			if (!is_valid(ptr[z][i]))
				return (write(2, "Error\n", 6), -1);
			number = ft_atoi(ptr[z][i]);
			if (number > INT_MAX || number < INT_MIN)
				return (write(2, "Error\n", 6), -1);
			if (!is_unique(number, arr, in))
				return (write(2, "Error\n", 6), -1);
			arr[in++] = number;
			i++;
		}
		i = 0;
	}
	return (in);
}
