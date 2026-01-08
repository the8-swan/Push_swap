/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:41:09 by obakri            #+#    #+#             */
/*   Updated: 2026/01/06 09:52:38 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_s_p(t_stack **a, t_stack **b, char *instruction)
{
	if (instruction[0] == 'p')
	{
		if (instruction[1] == 'a')
			ft_push_bonus(a, b, 'a');
		else if (instruction[1] == 'b')
			ft_push_bonus(a, b, 'b');
	}
	else
	{
		if (instruction[1] == 'a')
			ft_swap_bonus(*a, NULL);
		else if (instruction[1] == 'b')
			ft_swap_bonus(NULL, *b);
		else if (instruction[1] == 's')
			ft_swap_bonus(*a, *b);
	}
}

void	execute_r_rr(t_stack **a, t_stack **b, char *instruction)
{
	if (instruction[0] == 'r' && instruction[2] != '\n')
	{
		if (instruction[2] == 'a')
			ft_rrotate_bonus(a, NULL);
		else if (instruction[2] == 'b')
			ft_rrotate_bonus(NULL, b);
		else if (instruction[2] == 'r')
			ft_rrotate_bonus(a, b);
	}
	else
	{
		if (instruction[1] == 'a')
			ft_rotate_bonus(a, NULL);
		else if (instruction[1] == 'b')
			ft_rotate_bonus(NULL, b);
		else if (instruction[1] == 'r')
			ft_rotate_bonus(a, b);
	}
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	init_ops(char **ptr)
{
	ptr[0] = "sa\n";
	ptr[1] = "sb\n";
	ptr[2] = "ss\n";
	ptr[3] = "pa\n";
	ptr[4] = "pb\n";
	ptr[5] = "ra\n";
	ptr[6] = "rb\n";
	ptr[7] = "rr\n";
	ptr[8] = "rra\n";
	ptr[9] = "rrb\n";
	ptr[10] = "rrr\n";
	ptr[11] = NULL;
}

int	is_instruction(char *instruction)
{
	char	*ptr[12];
	int		i;

	i = 0;
	init_ops(ptr);
	while (ptr[i])
	{
		if (ft_strcmp(instruction, ptr[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
