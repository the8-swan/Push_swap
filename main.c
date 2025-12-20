#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"


int nums_counter(char	**ptr){
	int c = 0;
	while(ptr[c]!=NULL)
		c++;
	return c;
}

int fill_arr(int *arr, char **ptr){
	int i = 0;
	int j = 0;
	while(ptr[i]){
		while(ptr[i][j]){
			if(!ft_isdigit(ptr[i][j])){
				write(1,"Error\n",6);
				printf("hello");
				return -1;
			}
			j++;
		}
		arr[i] = ft_atoi(ptr[i]);
		j=0;
		i++;
	}
	return 1;
}


int main(int argc,char **argv){
	if(argv[1]==NULL){
		write(1,"Error\n",6);
		return 0;
	}
	char **ptr= ft_split(argv[1],' ');
	int c = nums_counter(ptr);
	int arr[c];
	int d = fill_arr(arr,ptr); 
	printf("%d",d);
	return 0;
}