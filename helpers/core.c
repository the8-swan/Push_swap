#include "../push_swap.h"





void	push_swap(int	*arr, int c)
{
	stack 	*a;
	stack	*b;

	b = create_stack(arr,c);
	a = create_stack(arr,c);
	ft_swap(a,b);
	while(b){
		printf("%d\n",b->num);
		b=b->next;
	}
	while(a){
		printf("%d\n",a->num);
		a=a->next;
	}

}