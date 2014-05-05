
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
  

// Sort the input array and return the number of inversions in the array
// =============================================================================

unsigned long counting_merge_sort(int arr[], int temp[], int left, int right)
{
    int mid;
    unsigned long inv_count = 0;
    
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


int main()  
{      
    
    int length, tests;

    cin >> tests;
    
    while(tests--){
	
	cin >> length;
	
	// Allocate a new array at the specified length, and load it with
	// the items

	int* items = new int[length];
	int* temp = new int[length];

	for(int i = 0; i < length; i++){
	    
	    cin >> items[i];
	}

	cout << counting_merge_sort(items, temp, 0, length - 1) << endl;
	
	delete[] items;
	delete[] temp;
    
    }

    return 0;

} 