#include <stdio.h>

int LinearSearch(int _arrayToSearch[], int _target);
int BinarySearch(int _arrayToSearch[], int target);
int main (void)
{
	
	int values[6] = {0,1,2,3,4,5};
	int target;
	printf("Target: ");
	scanf("%d", &target);
	int found = BinarySearch(values,target);
	printf("Found: %d",found);

}



int LinearSearch(int _arrayToSearch[], int target)
{
	// j = to the length of the array
	int j = sizeof(_arrayToSearch);
	int looper= 0;
for(int i = 0; i<j;i++)
{
	if(target == _arrayToSearch[i])
	{
		printf("Location: %d \n",i+1);
		looper++;
		
	}
	
	
}
if (looper != 0)
{
	return looper;
}
else
	return 0;
}

int BinarySearch(int _arrayToSearch[], int target)
{
	int arraySize = sizeof(_arrayToSearch);
	int first = 0;
	int last = arraySize -1;
	int mid = (first +last) /2;
	int loct= 0;
	int found =0;
	
	

	
		while(first <= last)
	   {
		
					if(target> _arrayToSearch[mid])
						{
							first = mid +1;
						}
				    else if(_arrayToSearch[mid] == target)
				    {
				    	printf("%d Found at location: %d\n", target, mid+1);
				    	return 1;
					}
					else
					{
						last = mid -1;
					}
					mid = (first + last)/2;
		
	   }
	   if(first > last)
	   {
	   	printf("target not found!\n");
	   }

	
	return found;
	
	}
