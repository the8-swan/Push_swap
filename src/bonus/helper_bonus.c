/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 20:47:45 by obakri            #+#    #+#             */
/*   Updated: 2026/01/08 20:48:11 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute_operation(char *instruction, t_stack **a, t_stack **b)
{
	if (instruction[0] == 'p' || instruction[0] == 's')
		execute_s_p(a, b, instruction);
	else
		execute_r_rr(a, b, instruction);
}
