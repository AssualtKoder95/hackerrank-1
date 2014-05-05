
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>

using namespace std;

int main()  
{      
    
    unsigned int L,R;
    unsigned int best = 0;
    
    cin >> L >> R;
    
    // Yay! Brute forcin it!
    // ========================================
    
    for(unsigned int i = L; i <= R; i++){
	
	for(unsigned int j = L; j <= R; j++){
	    
	    unsigned int test = i^j;
	    
	    if(test > best){
		
		best = test;
	    }
	}
    }

    
    cout << best << endl;
 
    return 0;  
} 