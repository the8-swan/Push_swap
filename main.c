#include "push_swap.h"

static int check_empty(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (c == 0 && str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
		{
			c++;
			break;
		}
	}

	return (c);
}

int main(int argc, char **argv)
{
	char ***ptr;
	int i;
	int counter;
	int *arr;

	i = 0;
	counter = 0;
	if (argc < 2)
		return (0);
	ptr = malloc(sizeof(char **) * argc);
	if (!ptr)
		return 0;
	while (i + 1 < argc)
	{
		if (!check_empty(argv[i + 1]))
		{
			free_ptr(ptr);
			return (write(1, "Error\n", 6), 0);
		}

		ptr[i] = ft_split(argv[i + 1], ' ');
		if (!ptr[i])
		{
			free_ptr(ptr);
			return (0);
		}
		counter += digits_counter(ptr[i]);
		i++;
	}
	ptr[i] = NULL;
	arr = malloc(sizeof(int) * counter);
	if (!arr)
	{
		free_ptr(ptr);
		return (0);
	}
	counter = fill_arr(arr, ptr);
	if (counter == -1)
	{
		free_ptr(ptr);
		free(arr);
		return (0);
	}
	push_swap(arr, counter);
	free_ptr(ptr);
	free(arr);
	return (0);
}