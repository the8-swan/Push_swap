#include "../push_swap.h"


void	sort_two(stack	*a)
{
	if(a->num > (a->next)->num)
	{
		ft_swap(a,NULL);
	}
}


/*
  // Calculate for EVERY node in B
    for each node in b:
        calculate_costs(node);
    
    // Find the one with MINIMUM cost
    cheapest = find_min_cost(b);
    
    // Move ONLY that one
    move_to_a(cheapest);
*/



void	positional_sort(stack **a , stack **b)
{
	stack *tmp;

	tmp = *a;
	while(*b)
	{
		update_position(a);
		update_position(b);
		while (tmp)
		{
			calculate_costs(a, tmp);
			tmp=tmp->next
		}
		
		*b = (*b)->next;
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
	positional_sort(&a, &b);

	while(a){
		printf("%d and it's index is : %d it's position is %d \n",a->num,a->index,a->position);
		a= a->next;
	}
	printf("************************\n");
	while(b){
		printf("%d and it's index is : %d it's position is %d \n",b->num,b->index,b->position);
		b=b->next;
	}

}