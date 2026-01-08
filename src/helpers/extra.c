/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:36:15 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 18:37:16 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}
int	check_empty(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (c == 0 && str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
		{
			c++;
			break ;
		}
	}
	return (c);
}
int	fill_ptr(char ***ptr, char **argv, int argc)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i + 1 < argc)
	{
		if (!check_empty(argv[i + 1]))
		{
			free_ptr(ptr, NULL);
			return (write(1, "Error\n", 6), -1);
		}
		ptr[i] = ft_split(argv[i + 1], ' ');
		if (!ptr[i])
			return (free_ptr(ptr, NULL), 0);
		counter += digits_counter(ptr[i]);
		i++;
	}
	ptr[i] = NULL;
	return (counter);
}

long	ft_atoi(const char *str)
{
	size_t		i;
	long		result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

size_t	ft_strl(const char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if(str[i] == '-' || str[i] == '+')
		i++;
	while(str[i] && str[i] == '0')
		i++;
	while (str[i])
	{
		i++;
		counter++;
	}
	return (counter);
}