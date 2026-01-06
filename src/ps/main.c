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
	counter = fill_ptr(ptr, argv, argc);
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
