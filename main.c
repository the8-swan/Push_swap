#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

int print_error(){
	write(1, "Error\n", 6);
	return -1;
}

int nums_counter(char **ptr)
{
	int c = 0;
	while (ptr[c] != NULL)
		c++;
	return c;
}
int is_unique(int value, int *arr, int index)
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
	return 1;
}

int main(int argc, char **argv)
{
	if (argv[1] == NULL)
	{
		write(1, "Error\n", 6);
		return 0;
	}
	char **ptr = ft_split(argv[1], ' ');
	int c = nums_counter(ptr);
	int arr[c];
	int d = fill_arr(arr, ptr);
	return 0;
}