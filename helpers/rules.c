#include "../push_swap.h"

void ft_swap(stack *a, stack *b)
{
	int c;

	c = 0;
	if (a && a->next != NULL)
	{
		swap_helper(a);
		if (!b)
		{
			write(1, "sa\n", 3);
			return;
		}
		c++;
	}
	if (b && b->next != NULL)
	{
		swap_helper(b);
		if (!a)
		{
			write(1, "sb\n", 3);
			return;
		}
		c++;
	}
	if (c == 2)
		write(1, "ss\n", 3);
}

void ft_rrotate(stack **a, stack **b)
{
	int ca;
	int cb;

	ca = 0;
	cb = 0;
	if (a!=NULL && *a && (*a)->next)
	{
		rrotate_helper(a);
		ca = 1;
	}
	if (b!=NULL && *b && (*b)->next)
	{
		rrotate_helper(b);
		cb = 1;
	}
	if (ca && cb)
		write(1, "rrr\n", 4);
	else if (ca)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void ft_rotate(stack **a, stack **b)
{
	int ca;
	int cb;

	ca = 0;
	cb = 0;
	if (a!=NULL && *a && (*a)->next)
	{
		rotate_helper(a);
		ca = 1;
	}
	if (b!=NULL && *b && (*b)->next)
	{
		rotate_helper(b);
		cb = 1;
	}
	if (ca && cb)
		write(1, "rr\n", 3);
	else if (ca)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void ft_push(stack **a, stack **b, char c)
{
	if (c == 'a' && *b)
	{
		push_helper(a, b);
		write(1, "pa\n", 3);
	}
	else if (c == 'b' && *a)
	{
		push_helper(b, a);
		write(1, "pb\n", 3);
	}
}


void	push_to_b(stack	**a, stack **b,	int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		ft_push(a, b, 'b');
		i++;
	}
}