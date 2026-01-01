#include "../push_swap.h"

static int print_error()
{
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

int fill_arr(int *arr, char ***ptr)
{
	int i;
	int in;
	int j;
	int z;

	in = 0;
	z = 0;
	i = 0;
	j = 0;
	while (ptr[z])
	{
		while (ptr[z][i])
		{
			while (ptr[z][i][j])
			{
				if (!ft_isdigit(ptr[z][i][j]))
					return (write(1, "Error\n", 6), -1);
				j++;
			}
			arr[in] = ft_atoi(ptr[z][i]);
			if (arr[in] > INT_MAX || arr[in] < INT_MIN)
				return (write(1, "Error\n", 6), -1);
			if (!is_unique(ft_atoi(ptr[z][i]), arr, i))
				return (write(1, "Error\n", 6), -1);
			j = 0;
			i++;
			in++;
		}
		i = 0;
		z++;
	}
	return (i);
}