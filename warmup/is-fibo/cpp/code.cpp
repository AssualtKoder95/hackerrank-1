
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <map>  

using namespace std;


// There are less than 50 fibonacci numbers under 10^10 but potentially
// up to 10,000 numbers to test. So by far the most efficient way to solve
// this problem is to create a LUT of all fibonacci numbers under 10^10
// and check against it

map <unsigned long, bool> scratch;

unsigned long fib(unsigned int n) {
    
    if (n == 0) return 0;
    
    unsigned long previous = 0;
    unsigned long current = 1;
    
    for (unsigned int i = 1; i < n; ++i) {
	
        unsigned long next = previous + current;
        previous = current;
        current = next;
    }
    
    return current;
}

int load_cache(unsigned long max) {
    
    unsigned long res = 0;
    unsigned int ord = 1;
    
    while (res < max) {
	
	res = fib(ord);
        scratch[res] = true;
	ord++;
    }
    
    return 0;
    
}


int main()  
{      
    
    load_cache(10000000000 + 1);
    
    int cases;  
    unsigned long f;  
    
    cin >> cases;  
    
    while (cases--)  
    {  
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