
#include <iostream>  
#include <map>  

using namespace std;

int main()  
{      

    // There are less than 50 fibonacci numbers under 10^10 but potentially
    // up to 10,000 numbers to test. So by far the most efficient way to solve
    // this problem is to create a LUT of all fibonacci numbers under 10^10
    // and check against it

    map <unsigned long, bool> scratch;    

    unsigned long max = 10000000000 + 1;

    unsigned long previous = 0;
    unsigned long current = 1;
    int i = 1;
    
    while(current < max) {
	
	scratch[current] = true;

        unsigned long next = previous + current;
        previous = current;
        current = next;

	i++;
    }
    
    int cases;  
    cin >> cases;  
    
    while (cases--)  
    {  
	unsigned long f; 
	cin >> f;  

	// The map.count() method can search all keys in O(log n) 
	// time, which is much faster than doing a linear search
	
	if(scratch.count(f) > 0){

	    cout << "IsFibo" << endl; 
	}
	else {

	    cout << "IsNotFibo" << endl; 
	}
    }  
    
    return 0;  
} 