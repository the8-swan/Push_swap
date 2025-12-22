#include "../push_swap.h"

static int print_error(){
	write(1, "Error\n", 6);
	return -1;
}

int digits_counter(char **ptr)
{
	int c = 0;
	while (ptr[c] != NULL)
		c++;
	return c;
}

static int is_unique(int value, int *arr, int index)
{
	int i = 0;
	while (i < index)
	{
		if (value == arr[i])
			return 0;
		i++;
	}
	return 1;
}

int fill_arr(int *arr, char **ptr)
{
	int i = 0;
	int j = 0;
	long number = 0;
	while (ptr[i])
	{
		while (ptr[i][j])
		{
			if (!ft_isdigit(ptr[i][j]))
				return (write(1, "Error\n", 6),-1);
			j++;
		}
		number = ft_atoi(ptr[i]);
		if (number > 2147483647 || number < -2147483648)
				return (write(1, "Error\n", 6),-1);
		if (!is_unique(ft_atoi(ptr[i]), arr, i))
				return (write(1, "Error\n", 6),-1);
		arr[i] = ft_atoi(ptr[i]);
		j = 0;
		i++;
	}
	return i;
}

void fill_ptr(char **ptr, char **argv, int argc)
{
	int i ;

	i = 0;
	while(i<argc-1)
	{
		ptr[i] = argv[i+1];
		i++;
	}
	ptr[i] = NULL;
}
 
