#include "../push_swap.h"


int	stack_size(stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	assign_index(stack *a, int *arr, int size)
{
	int	i;

	while (a)
	{
		i = 0;
		while (i<size)
		{
			if (a->num == arr[i])
			{
				a->index = i;
				break;
			}
			i++;
		}
		a = a->next;
	}
}

void	update_position(stack *a)
{
	int size;
	int	i;

	size = stack_size(a);
	i = 0;
	while (i < size)
	{
		a->position = i;
		i++;
		a = a-> next;
	}
}