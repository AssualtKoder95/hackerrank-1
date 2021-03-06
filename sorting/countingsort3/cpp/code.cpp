
#include <cstdlib>
#include <iostream>
#include <string>
 
using namespace std;
  
void counting_sort(int items[], int length, int bins[]);

// A totally vanilla counting sort
// =============================================================================

void counting_sort(int items[], int length, int bins[]) {
    
    
    for (int i = 0; i < length; i++) {
	
	bins[items[i]]++;
    }  
}
 
int main()  
{      
    
    int length;
    string discard;

    cin >> length;

    // Allocate a new array at the specified length, and load it with
    // the items

    int* items = new int[length];

    for(int i = 0; i < length; i++){

	cin >> items[i] >> discard;
    }
    
    // Create an array of bins that has a length equal to the total
    // number of different item types, and initialize all cells to zero
    
    int bin_count = 100;
    int* bins = new int[bin_count];  
    
    for(int i = 0; i < bin_count; i++){

	bins[i] = 0;
    }    

    counting_sort(items, length, bins); 

    // Print [bin number] [bin total] times

    int total = 0;
    
    for(int k = 0; k < bin_count; k++){

	total += bins[k];   	
	cout << total << " ";	
    }

    cout << endl;    

    delete[] items;
    delete[] bins;

    return 0;

} 