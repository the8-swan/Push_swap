/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:32:06 by obakri            #+#    #+#             */
/*   Updated: 2026/01/08 16:20:56 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

void	execute_s_p(t_stack **a, t_stack **b, char *instruction);
void	execute_r_rr(t_stack **a, t_stack **b, char *instruction);
void	checker(int *arr, int c);
void	ft_swap_bonus(t_stack *a, t_stack *b);
void	ft_rrotate_bonus(t_stack **a, t_stack **b);
void	ft_rotate_bonus(t_stack **a, t_stack **b);
void	ft_push_bonus(t_stack **a, t_stack **b, char c);
void	check_sorted(t_stack *a);

int		is_instruction(char *instruction);

#endif
