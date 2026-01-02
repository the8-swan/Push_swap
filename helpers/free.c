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