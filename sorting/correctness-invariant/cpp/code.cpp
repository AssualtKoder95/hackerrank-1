
#include <cstdlib>
#include <iostream>
 
using namespace std;
  
void insertion_sort(int arr[], int length);

// A totally vanilla insertion sort
// =============================================================================

void insertion_sort(int arr[], int length) {
    
    int i, j ,tmp;
    
    for (i = 1; i < length; i++) {
	
	j = i;
	
	while (j > 0 && arr[j - 1] > arr[j]) {
	    
	    tmp = arr[j];
	    arr[j] = arr[j - 1];
	    arr[j - 1] = tmp;
	    j--;    
	}	
    }  
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

    insertion_sort(items, length);
    
    // Print the sorted array
    
    for(int i = 0; i < length; i++){

	cout << items[i] << " ";
    }    

    delete[] items;

    return 0;

} 
