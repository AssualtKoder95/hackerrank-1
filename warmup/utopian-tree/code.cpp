
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <map>  

using namespace std;

int main()  
{      
    
    int cases, n, pass;
    unsigned long total;  
    
    cin >> cases;  
    
    while (cases--)  
    {  
	cin >> n;  

	total = 1;
	pass = 0;

	while (pass < n){
	    
	    if(pass % 2 == 0){
		
		total = total * 2;
	    }
	    else {
		total++;
	    }
	    
	    pass++;
	    
	}
	
	cout << total << endl; 	
	
    }  
    
    return 0;  
} 