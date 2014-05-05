

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>  
#include <algorithm> 

using namespace std;


// Sorts supplied array using quicksort sort. Returns number of swaps
// made during algorithm.
// =============================================================================

void swap(int &a, int &b) {
    
    int temp = a;
    a = b;
    b = temp;
}

int counting_partition(int *a, int start, int end, int &ret) {
    
    int sum = 0;
    int p = start - 1;
    
    for (int i = start; i <= end - 1; i++) {
	
	if (a[i] < a[end]) {
	    
	    swap(a[++p], a[i]);
	    sum++;
	}
    }
    
    swap(a[++p], a[end]);
    sum++;
    
    ret = p;
    return sum;
}

int counting_quicksort(int *a, int start, int end) {
    
    int sum = 0;
    
    if (start < end) {
	
	int mid;
	sum += counting_partition(a, start, end, mid);
	sum += counting_quicksort(a, start, mid - 1);
	sum += counting_quicksort(a, mid + 1, end);
    }
    
    return sum;
}



// Sorts supplied array using insertion sort. Returns number of swaps
// made during algorithm.
// =============================================================================

long counting_insertion_sort(int arr[], int length) {
    
    int i, j,tmp;
    long count = 0;
    
    for (i = 1; i < length; i++) {
	
	j = i;
	
	while (j > 0 && arr[j - 1] > arr[j]) {
	    
	    tmp = arr[j];
	    arr[j] = arr[j - 1];
	    arr[j - 1] = tmp;
	    j--; 
	    count++;
	}	
    } 
    
    return count;
}
 

int main()  
{      
    
    int length, tmp;

    cin >> length;

    // Allocate a new array at the specified length, and load it with
    // the items

    int* items_a = new int[length];
    int* items_b = new int[length];

    for(int i = 0; i < length; i++){

	cin >> tmp;
	items_a[i] = items_b[i] = tmp;
    }

    cout << counting_insertion_sort(items_a, length) - counting_quicksort(items_b, 0, length-1) << endl;


    delete[] items_a;
    delete[] items_b;

    return 0;

} 

