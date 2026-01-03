/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:55:01 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 18:23:46 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_empty(char *str)
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

static int	fill_ptr(char ***ptr, int *arr, char **argv, int argc)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i + 1 < argc)
	{
		if (!check_empty(argv[i + 1]))
		{
			free_ptr(ptr, arr);
			return (write(1, "Error\n", 6), -1);
		}
		ptr[i] = ft_split(argv[i + 1], ' ');
		if (!ptr[i])
			return (free_ptr(ptr, arr), 0);
		counter += digits_counter(ptr[i]);
		i++;
	}
	ptr[i] = NULL;
	return (counter);
}

int	main(int argc, char **argv)
{
	char	***ptr;
	int		counter;
	int		*arr;

	counter = 0;
	if (argc < 2)
		return (0);
	ptr = malloc(sizeof(char **) * argc);
	if (!ptr)
		return (0);
	counter = fill_ptr(ptr, arr, argv, argc);
	if (counter == -1)
		return (0);
	arr = malloc(sizeof(int) * counter);
	if (!arr)
		return (free_ptr(ptr, arr), 0);
	counter = fill_arr(arr, ptr);
	if (counter == -1)
		return (free_ptr(ptr, arr), 0);
	push_swap(arr, counter);
	free_ptr(ptr, arr);
	return (0);
}
