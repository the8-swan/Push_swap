

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>



typedef struct  stack
{
	int num;
	struct stack *next;
	
}stack;

typedef struct s_node{
	int				val;
	int				ind;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
} t_stack;



int digits_counter(char **ptr);

char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
long	ft_atoi(const char *str);
int fill_arr(int *arr, char **ptr);
void fill_ptr(char **ptr, char **argv, int argc);
stack *create_stack(int *arr,int c);
void	push_swap(int	*arr, int c);
void ft_swap(stack *a,stack *b);







#endif