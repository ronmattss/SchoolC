// Activity: Selection Sort Algorithm           Date: 1/2/19
// Name: Ron Matthew R. Rivera 
// Course & Section: BSCS 1-1   

// Using DevC++
#include <stdio.h>

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

    //  for each iteration move the i of unsorted subarray 
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
void printSortedArray(int arr[], int size)
{
    int i;
    printf("Your sorted Array: ");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main(void)
{
    int arrSize = 10;
    int unSorted[10];
    printf("Enter 10 values for the array \n");
    for (int i = 0; i < arrSize; i++)
    {
        printf("Enter the value for element %d: ", i);
        scanf(" %d", &unSorted[i]);
    }
    selectionSort(unSorted, arrSize);
    printSortedArray(unSorted, arrSize);

}

