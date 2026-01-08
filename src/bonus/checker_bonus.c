/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:35:00 by obakri            #+#    #+#             */
/*   Updated: 2026/01/08 20:47:30 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_sorted(t_stack *a)
{
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
}

static void	handle_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_list(&a);
	free_list(&b);
}

void	checker(int *arr, int c)
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	a = create_stack(arr, c);
	b = NULL;
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		if (is_instruction(instruction))
			execute_operation(instruction, &a, &b);
		else
		{
			handle_error(a, b);
			return ;
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	free_list(&b);
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
