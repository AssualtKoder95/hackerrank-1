
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  

using namespace std;

int main()  
{      
    
    int cases, n, c, m, trade, wrappers;  
    unsigned long total;  
    
    cin >> cases;  
    
    while (cases--)  
    {  
	cin >> n >> c >> m;  

	// Calculate the number of chocolates that can be bought
	// for the given amount of money
	
	total = wrappers = n / c;

	// Then iteratively trade wrappers for chocolates, topping
	// up the number of wrappers on each pass, uuntil we run 
	// out of wrappers
	
	while (wrappers >= m){
	    
	    total += trade = wrappers / m;
	    wrappers = wrappers % m;
	    wrappers += trade;
	    
	}
	
	cout << total << endl; 	
	
    }  
    
    return 0;  
} 