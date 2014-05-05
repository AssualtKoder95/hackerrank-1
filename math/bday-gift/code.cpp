#include <cstdio>
#include <iostream>

using namespace std;

// This problem is trivial to solve. Each item has a 50% probability of
// being selected. The answer is the sum of all items, divided by 2.


int main() {
 
    // Get total number of testcases
    int total_items, item;
    
    // The testcases for this challenge are poorly designed. The fact they're using one point
    // after the decimal place implies you need to use a float. The range of a float on a 64
    // bit system is -10^309 to 10^309. The requirements are up to 40 numbers up to 10^9 large,
    // which makes the largest possible sum 4 * 10^10, which is well below a float's 10^309 overflow
    // point. Yet, if you use a float, half the unit tests fail, because the author is testing for
    // higher *precision* than a 64 bit float offers and doesn't mention anything about this
    // in their problem description. Using a 256 bit float (long double) breaks the printf() function
    // under Linux (it works in Windows) so we use a 128 bit float (double) instead.
    
    double total = 0;
    
    cin >> total_items;
   
    // Iterate through each testcase
    for(int i = 0; i < total_items; i++){
		
	cin >> item;
	
	// The "2.0" is important. Otherwise it will do integer division.
	total += item / 2.0; 
	
    }
    
    // Print it to one decimal place precision
    printf("%.1lf\n", total);
    
    return 0;
    
}