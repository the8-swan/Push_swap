#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>



typedef struct  stack
{
	int num;
	int	index;
	int position;
	int	target;
	int costb;
	int costa;
	struct stack *next;

}stack;

char	**ft_split(char const *s, char c);

long	ft_atoi(const char *str);

int	fill_arr(int *arr, char ***ptr);
int	ft_isdigit(int c);
int	digits_counter(char **ptr);
int is_sorted(stack	*a);
int	stack_size(stack *a);
int find_target(stack *a, stack *tmp);
int	calculate_costb(stack *b, stack *tmp);
int	ft_abs(int number);
int is_valid(char *ptr);
int	ft_isdigit(int c);
void free_ptr(char ***ptr);

void	calculate_costa(stack *a, stack *tmp);



stack	*before_lastnode(stack	*s);
stack	*create_stack(int *arr,int c);
stack	*last_node(stack	*head);

void	add_back(stack **head, stack *new);
void	add_front(stack **lst, stack *new);
void	rotate_helper(stack **a);
void	rrotate_helper(stack **a);
void	swap_helper(stack *head);
void	ft_push(stack **a, stack **b, char c);
void	push_helper(stack **a, stack **b);
void	push_swap(int	*arr, int c);
void	ft_swap(stack *a, stack *b);
void	ft_rrotate(stack **a, stack **b);
void	ft_rotate(stack **a, stack **b);
void	quick_sort(int *arr, int start, int end);
void	assign_index(stack *a, int *arr, int size);
void	push_to_b(stack	**a, stack **b,	int c);
void	update_position(stack *a);
void	positional_sort(stack **a , stack **b, int c);
void	sort_three(stack **a);
void	rotate_to_position(stack **a);
void	free_list(stack **stack);



#endif