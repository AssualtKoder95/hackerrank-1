#include <stdio.h>
#include <stdlib.h>
  
int counting_merge_sort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);
  

// Sort the input array and return the number of inversions in the array
// =============================================================================

int counting_merge_sort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    
    if (right > left)
    {
	// Split the array into two halves, and sort each half, adding
	// the inversions found in each half
	
	mid = ((right + left)/2) + 1;

	inv_count  = counting_merge_sort(arr, temp, left, mid-1);
	inv_count += counting_merge_sort(arr, temp, mid, right);

	// Merge the two halves, adding the inversions found during the merge

	int i = left; // index for left subarray
	int j = mid;  // index for right subarray
	int k = left; // index for merged subarray

	while ((i <= mid - 1) && (j <= right))
	{
	    if (arr[i] <= arr[j]){

		temp[k++] = arr[i++];
	    }
	    else {

		temp[k++] = arr[j++];

		// Each time we pick an item from the RIGHT subarray, increment
		// the inversion count by the number of items REMAINING in the
		// LEFT subarray

		inv_count += (mid - i);
	    }
	}

	// Copy remaining elements of left subarray (if any)
	while (i <= mid - 1){
	    temp[k++] = arr[i++];
	}

	// Copy remaining elements of right subarray (if any)
	while (j <= right){
	    temp[k++] = arr[j++];
	}

	// Copy merged elements to original array
	for (i=left; i <= right; i++){
	    arr[i] = temp[i];
	}
    }
    
    return inv_count;
}
  

// Main
// =============================================================================

int main(int argv, char** args)
{
    int arr[] = {2,1,3,1,2};
    int array_size = 5;

    //int *temp = (int *)malloc(sizeof(int)*array_size);
    
    int* temp = new int[array_size];

    printf("Number of inversions are %d \n", counting_merge_sort(arr, temp, 0, array_size - 1));

    return 0;
}