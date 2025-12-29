#include "../push_swap.h"
static int v =0;


void	sort_two(stack	*a)
{
	if(a->num > (a->next)->num)
	{
		ft_swap(a,NULL);
	}
}

static stack	*find_min_cost(stack *b)
{
	stack *cheapest;
	int sum;

	cheapest = NULL;
	sum = INT_MAX;
	while(b)
	{
		if(b->costa + b->costb < sum)
		{
			sum = b->costa + b->costb;
			cheapest = b; 
		}
		b = b->next;
	}
	return cheapest;
}

static void move_to_a(stack **a , stack **b, stack *cheapest)
{
		while(cheapest->costa < 0 && cheapest->costb < 0)
		{
			ft_rrotate(a,b);
			(cheapest->costa)++;
			(cheapest->costb)++;
			v++;

		}
		while(cheapest->costa > 0 && cheapest->costb > 0)
		{
			ft_rotate(a,b);
			(cheapest->costa)--;
			(cheapest->costb)--;
			v++;

		}
		while (cheapest->costa > 0)
		{
			ft_rotate(a,NULL);
			(cheapest->costa)--;
			(cheapest->costb)--;
			v++;
		}
		while (cheapest->costa < 0)
		{
			ft_rotate(a,NULL);
			(cheapest->costa)++;
			(cheapest->costb)++;
			v++;
		}
		while (cheapest->costb > 0)
		{
			ft_rotate(NULL,b);
			(cheapest->costb)--;
			(cheapest->costb)--;
			v++;
		}
		while (cheapest->costb < 0)
		{
			ft_rotate(NULL,b);
			(cheapest->costb)++;
			(cheapest->costb);
			v++;
		}
}
	

void	positional_sort(stack **a , stack *b)
{
	stack *tmp;
	stack *cheapest;

	while(b)
	{
		tmp = b;
		update_position(*a);
		update_position(b);
		while (tmp)
		{
			 calculate_costa(a,tmp);
			tmp->costb = calculate_costb(b,tmp);
			tmp=tmp->next;
		}
		tmp = b;
		cheapest = find_min_cost(tmp);
		move_to_a(a,&b,cheapest);
		b = b->next;
	}
}

void	push_swap(int	*arr, int c)
{
	stack 	*a;
	stack	*b;
	int		i;

	i = 0;
	a = create_stack(arr, c);
	b = NULL;
	if (is_sorted(a))
		return ;
	quick_sort(arr, 0, c - 1);
	assign_index(a, arr, c);
	push_to_b(&a, &b, c - 3);
	positional_sort(&a, b);
/*
	while(a){
		printf("%d and it's index is : %d it's position is %d \n",a->num,a->index,a->position);
		a= a->next;
	}
	printf("************************\n");*/

/*	while(b){
		printf("%d and it's costa is : %d it's target vostb is %d , it's target is : %d \n",b->num,b->costa,b->costb,b->target);
		b=b->next;
	}
	*/
	printf("%d : ",v);

}