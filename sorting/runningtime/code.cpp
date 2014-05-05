
#include <cstdlib>
#include <iostream>
 
using namespace std;
  
long counting_insertion_sort(int arr[], int length);


// Sorts supplied array using insertion sort. Returns number of swaps
// made during insertion sort algorithm.
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
    
    int length;

    cin >> length;

    // Allocate a new array at the specified length, and load it with
    // the items

    int* items = new int[length];

    for(int i = 0; i < length; i++){

	cin >> items[i];
    }

    cout << counting_insertion_sort(items, length);  

    delete[] items;

    return 0;

} 
