#include <stdio.h>
//Fibonacci series iterative
// Created by: Ron Rivera

int main(void)
{
	int seriesSize, first =0, second = 1, last,counter;
	
	printf("prints a fibonacci series. \n");
	printf("Input a positive integer number: ");
	scanf(" %d",&seriesSize);
	printf("First %d fibonacci number: \n", seriesSize);
	
	for(counter = 0; counter< seriesSize; counter++)
	{
		if(counter <=1)
		{
			last = counter;
		}
		else
		{
			last = first + second;
			first = second;
			second = last;
		}
		printf("%d\n", last);
	}
	
	

		
}


