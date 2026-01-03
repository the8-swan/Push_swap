/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obakri <obakri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:25:08 by obakri            #+#    #+#             */
/*   Updated: 2026/01/03 18:39:08 by obakri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct stack
{
	int				num;
	int				index;
	int				position;
	int				target;
	int				costb;
	int				costa;
	struct stack	*next;
}t_stack;

char	**ft_split(char const *s, char c);

long	ft_atoi(const char *str);

int		fill_arr(int *arr, char ***ptr);
int		ft_isdigit(int c);
int		digits_counter(char **ptr);
int		is_sorted(t_stack	*a);
int		stack_size(t_stack *a);
int		find_target(t_stack *a, t_stack *tmp);
int		calculate_costb(t_stack *b, t_stack *tmp);
int		ft_abs(int number);
int		is_valid(char *ptr);
int		ft_isdigit(int c);

t_stack	*before_lastnode(t_stack *s);
t_stack	*create_stack(int *arr, int c);
t_stack	*last_node(t_stack *head);

void	add_back(t_stack **head, t_stack *new);
void	add_front(t_stack **lst, t_stack *new);
void	rotate_helper(t_stack **a);
void	rrotate_helper(t_stack **a);
void	swap_helper(t_stack *head);
void	ft_push(t_stack **a, t_stack **b, char c);
void	push_helper(t_stack **a, t_stack **b);
void	push_swap(int *arr, int c);
void	ft_swap(t_stack *a, t_stack *b);
void	ft_rrotate(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **a, t_stack **b);
void	quick_sort(int *arr, int start, int end);
void	assign_index(t_stack *a, int *arr, int size);
void	push_to_b(t_stack **a, t_stack **b,	int c);
void	update_position(t_stack *a);
void	positional_sort(t_stack **a, t_stack **b, int c);
void	sort_three(t_stack **a);
void	rotate_to_position(t_stack **a);
void	free_list(t_stack **stack);
void	free_ptr(char ***ptr, int *arr);
void	calculate_costa(t_stack *a, t_stack *tmp);
#endif
