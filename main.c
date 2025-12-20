#include <stdio.h>
#include "push_swap.h"


int nums_counter(char	**ptr){
	int c = 0;
	while(ptr[c]!=NULL)
		c++;
	return c;
}



int main(int argc,char **argv){
	if(argv[1]=='\0'){
		write(1,"Error\n",6);
	}
	char **ptr= ft_split(argv[1],' ');
	int c = nums_counter(ptr);
	int arr[c];
	int d = fill_arr(arr,ptr); 
	return 0;
}