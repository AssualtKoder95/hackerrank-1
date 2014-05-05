
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  

using namespace std;

int main()  
{      
    
    int cases;
    unsigned long n, a, b; 
    
    cin >> cases;

    while (cases--)  
    {  
	
	cin >> n;
	
	// Its a trivial mathematical progression. Just (n / 2) * 2, or if it doesn't
	// divide evenly (n/2) * ((n/2) + 1)
	
	a = b = (n / 2);
	
	if(n % 2){
	    
	    b++;
	}

	cout << (a * b) << endl; 	
	
    }  
    
    return 0;  
} 