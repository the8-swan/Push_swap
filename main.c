#include "push_swap.h"

int main(int argc, char **argv)
{
	char ***ptr;
	int i;
	int counter;
	int *arr;

	i = 0;
	ptr = malloc(sizeof(char **) * argc);
	if (!ptr)
		return 0;
	while (i + 1 < argc)
	{
		ptr[i] = ft_split(argv[i + 1],' ');
		if (!ptr[i])
			return (0);
		counter += digits_counter(ptr[i]);
		i++;
	}
	arr = malloc(sizeof(int) * counter);
	if (!arr)
			return (0);
	counter = fill_arr(arr, ptr);
	if(counter == -1)
		return (0);
	push_swap(arr,counter);
	return (0);
}