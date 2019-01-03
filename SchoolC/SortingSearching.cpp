// Activity: Binary Search			Date: 1/2/19
// Name: Ron Matthew R. Rivera 
// Course & Section: BSCS 1-1	

// Using DevC++
#include <stdio.h>

// using selection sort to make sure the array is sorted before the sort
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
// declare the BinarySearch method with parameters: parameter 1 = int array[], parameter 2 = int target
int BinarySearch(int _arrayToSearch[], int target);

int main(void)
{

	int arrSize = 10;
	int unSorted[10];
	// enter 10 values for the array
	printf("Enter 10 values for the array \n");
	for (int i = 0; i < arrSize; i++)
	{
		printf("Enter the value for element %d: ", i);
		scanf_s(" %d", &unSorted[i]);
	}
	// sort the array to make sure the search will execute correctly
	selectionSort(unSorted, arrSize);
	int values[6] = { 0,1,2,3,4,5 };   // set an example values to search
	int n = sizeof(unSorted) / sizeof(unSorted[0]);
	int target;						  // declare an int var named target
	printf("Search the value: ");
	scanf_s("%d", &target);		      // prompt the user to input a number to search
	int found = BinarySearch(unSorted, target);
	//printf("Found: %d", found);

}


// Binary search Algorithm
// parameter 1 is the array to search onto
// parameter 2 is the target to search
int BinarySearch(int _arrayToSearch[], int target)
{
	// declare arraySize as the size of _arrayToSearch
	// declare variables first, loct, and found to 0
	// declare last variable = to the arrayLength -1
	// declare mid variable as the middle of the index of the array
	int arraySize = sizeof(_arrayToSearch);
	int first = 0;
	int last = arraySize - 1;
	int mid = (first + last) / 2;
	int loct = 0;
	int found = 0;

	// loop the array while var first is <= last
	while (first <= last)
	{

		if (target > _arrayToSearch[mid])
		{
			first = mid + 1;
		}
		else if (_arrayToSearch[mid] == target)
		{
			printf("value %d Found at location: %d\n", target, mid + 1);
			// return 1 if value is fount in the array
			return 1;
		}
		else
		{
			last = mid - 1;
		}
		mid = (first + last) / 2;

	}
	if (first > last)
	{
		printf("target not found!\n");
	}
	// returns 0 if no value is found in the array
	return found;
}

// function to swap an array
void swap(int *xp, int *yp)
{
	// using pointers to swap elements in an array
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
// function Selection Sort
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	//  for each iteration move the i of unsorted array 
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in the unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]);
	}
}














