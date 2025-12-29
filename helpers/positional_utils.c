#include "../push_swap.h"

int find_target(stack *a, stack *tmp)
{
	int index;
	int position;

	index = INT_MAX;
	position = -1;
	while (a)
	{
		if (a->index > tmp->index && a->index < index)
		{
			index = a->index;
			position = a->position;
		}
		a = a->next;
	}
	if (position < 0)
	{
		while (a)
		{
			if (a->index < index)
			{
				index = a->index;
				position = a->position;
			}
			a = a->next;
		}
	}
	return (position);
}

void calculate_costa(stack **a, stack *tmp)
{
	int a_size;
	int target_position;

	a_size = stack_size(*a);
	target_position = find_target(*a, tmp);
}

int calculate_costb(stack *b, stack *tmp)
{
	int current_position;
	int b_size;

	current_position = tmp->position;
	b_size = stack_size(b);
	if (tmp->position <= b_size / 2)
		return (tmp->position);
	else
		return (-(b_size - tmp->position));
}
