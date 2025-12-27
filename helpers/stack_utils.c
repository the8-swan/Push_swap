#include "../push_swap.h"



void	assign_index(stack *a, int *arr, int size){
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