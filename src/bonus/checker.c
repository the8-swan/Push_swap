/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:35:00 by obakri            #+#    #+#             */
/*   Updated: 2026/01/06 09:40:30 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	check_sorted(t_stack *a)
{
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	checker(int *arr, int c)
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	a = create_stack(arr, c);
	b = NULL;
	while ((instruction = get_next_line(0)) != NULL)
	{
		if (is_instruction(instruction))
		{
			if (instruction[0] == 'p' || instruction[0] == 's')
				execute_s_p(&a, &b, instruction);
			else
				execute_r_rr(&a, &b, instruction);
		}
		else
		{
			write(1, "Error\n", 6);
			free_list(&a);
			free_list(&b);
			return ;
		}
		free(instruction);
	}
	check_sorted(a);
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
	counter = fill_ptr(ptr, argv, argc);
	if (counter == -1)
		return (0);
	arr = malloc(sizeof(int) * counter);
	if (!arr)
		return (free_ptr(ptr, arr), 0);
	counter = fill_arr(arr, ptr);
	if (counter == -1)
		return (free_ptr(ptr, arr), 0);
	checker(arr, counter);
	free_ptr(ptr, arr);
	return (0);
}
