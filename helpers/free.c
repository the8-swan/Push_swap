#include "../push_swap.h"


void free_list(stack **st)
{
	stack *next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

void free_ptr(char ***ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(ptr[i])
	{
		while(ptr[i][j])
		{
			free(ptr[i][j]);
			j++;
		}
		free(ptr[i]);
		j =0;
		i++;
	}
	free(ptr);
}