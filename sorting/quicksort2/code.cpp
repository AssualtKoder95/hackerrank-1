#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
 
void quick_sort(int a[], int first, int last);
int calc_pivot(int a[], int first, int last);
void swap(int& a, int& b);

using namespace std;
 
/**
 * Quicksort.
 * @param a - The array to be sorted.
 * @param first - The start of the sequence to be sorted.
 * @param last - The end of the sequence to be sorted.
*/
void quick_sort( int a[], int first, int last )
{
    int pivot;
 
    if(first < last)
    {
        pivot = calc_pivot(a, first, last);
        quick_sort(a, first, pivot-1);
        quick_sort(a, pivot+1, last);
    }
}
 
/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequence.
 * @param last - The end of the sequence.
 * @return - the pivot element
*/
int calc_pivot(int a[], int first, int last)
{
    int  p = first;
    int pivot = a[first];
 
    for(int i = first + 1; i <= last; i++)
    {
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivot)
        {
            p++;
            swap(a[i], a[p]);
        }
    }
 
    swap(a[p], a[first]);
    
    for(int i = first; i <= last; i++){
	cout << a[i] << " ";
    }
    
    cout << endl;
 
    return p;
}

///**
// * Uses the inefficient "dual list" algorithm to calculate a quicksort
// * iteration (because that's what hackerrank's tests use)
// * @param a - The array.
// * @param first - The start of the sequence.
// * @param last - The end of the sequence.
// * @return - index of the pivot
//*/
//int calc_pivot(int a[], int first, int last)
//{
//
//    int pivot = a[first];
//
//    vector<int> high;
//    vector<int> low;   
// 
//    for(int i = first + 1; i <= last; i++)
//    {
//        if(a[i] <= pivot)
//        {
//            low.push_back(a[i]);
//        }
//	else {
//	    high.push_back(a[i]); 
//	}
//    }
// 
//    int offset = 0;
//    
//    for(int i = 0; i < low.size(); i++)
//    {
//	a[i] = low[i];
//	offset++;
//    }
//    
//    a[offset++] = pivot;
//    
//    for(int i = 0; i < high.size(); i++)
//    {
//	a[i + offset] = high[i];
//    } 
//    
//    return first;
//
//}
 
 
/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
*/
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
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
    
    quick_sort(items, 0, length-1);
    
    for(int i = 0; i < length; i++){

	cout << items[i] << " ";
    }    

    delete[] items;

    return 0;

} 