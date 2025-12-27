#include "../push_swap.h"


void	sort_two(stack	*a)
{
	if(a->num > (a->next)->num)
	{
		ft_swap(a,NULL);
	}
}

/*
void	sort_three(stack	*a)
{
	if(a->num > (a->next)->num)
	{
		ft_swap(a,NULL);
	}
}*/



void	push_swap(int	*arr, int c)
{
	stack 	*a;
	stack	*b;

	int		i;

	i = 0;
	a = create_stack(arr, 3);
	b = create_stack(arr + 3, c - 3);
	quick_sort(arr, 0, c - 1);
	assign_index(a, arr, c);
	assign_index(b, arr, c);

	while(a){
		printf("%d and it's index is : %d it's position is %d \n",a->num,a->index,a->position);
		a= a->next;
	}
	printf("************************\n");
	while(b){
		printf("%d and it's index is : %d it's position is %d \n",b->num,b->index,b->position);
		b=b->next;
	}
	
	printf("************************\n");

	while(i<c)
	{
		printf("%d  , ",arr[i]);
		i++;
	}

	
}