#include "../push_swap.h"


static void swap(int *a, int *b)
{
	int c = *b;
	*b = *a;
	*a = c;
}


static int partitions(int *arr, int start, int end)
{
	int i;
	int pivot;
	int j;

	pivot = arr[end];
	i = start;
	j = start - 1;
	while (i < end)
	{
		if (arr[i] < pivot)
		{
			j++;
			swap(&arr[i], &arr[j]);
		}
		i++;
	}
	swap(&arr[end], &arr[++j]);
	return (j);
}

void quick_sort(int *arr, int start, int end)
{
	if(start < end){
		int p1 = partitions(arr, start, end);
		quick_sort(arr, start, p1 - 1);
		quick_sort(arr, p1 + 1, end);
	}
}



int is_sorted(stack	*a)
{
	while(a->next)
	{
		if(a->num > (a->next)->num)
			return (0);
		a = a->next;
	}
	return (1);
}