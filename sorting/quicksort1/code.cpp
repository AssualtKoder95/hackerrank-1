#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
 
using namespace std;
 

/**
 * Uses the inefficient "dual list" algorithm to calculate a quicksort
 * iteration (because that's what hackerrank's tests use)
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
*/
void bad_pivot(int a[], int first, int last)
{

    int pivot = a[first];

    vector<int> high;
    vector<int> low;   
 
    for(int i = first + 1; i <= last; i++)
    {
        if(a[i] <= pivot)
        {
            low.push_back(a[i]);
        }
	else {
	    high.push_back(a[i]); 
	}
    }
 
    int offset = 0;
    
    for(int i = 0; i < low.size(); i++)
    {
	a[i] = low[i];
	offset++;
    }
    
    a[offset++] = pivot;
    
    for(int i = 0; i < high.size(); i++)
    {
	a[i + offset] = high[i];
    }      

}
 
 
int main()  
{      
    
    int length, tmp;

    cin >> length;

    // Allocate a new array at the specified length, and load it with
    // the items

    int* items = new int[length];

    for(int i = 0; i < length; i++){

	cin >> tmp;
	items[i] = tmp;
    }
    
    bad_pivot(items, 0, length-1);
    
    for(int i = 0; i < length; i++){

	cout << items[i] << " ";
    }    

    delete[] items;

    return 0;

} 