#include "push_swap.h"


int main(int argc, char **argv)
{
	char	**ptr;
	int		c;
	int		*arr;

	c = 0;
	if (argc <= 1)
		return (write(1, "Error\n", 6), 0);
	if (argc > 2)
	{
		ptr = malloc(sizeof(char *) * argc );
		if (!ptr)
			return (0);
		fill_ptr(ptr, argv, argc);
	}else
	{
		ptr = ft_split(argv[1], ' ');
		arr = malloc(sizeof(int) * digits_counter(ptr));
		if (!arr)
			return (0);
	}
	arr = malloc(sizeof(int) * digits_counter(ptr));
	c = fill_arr(arr, ptr);
	if (c < 0)
		return (0);
	push_swap(arr,c);
	return (0);
}
