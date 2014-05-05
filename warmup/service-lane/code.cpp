
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <map>  

using namespace std;

int main()  
{      
    
    int length, cases, i, j, min; 
    int* road = NULL;
    
    cin >> length >> cases;
    
    // Dynamically allocate an array to hold the road widths,
    // then load them into the array
    
    road = new int[length];
    
    for(int i = 0; i < length; i++){

	cin >> road[i];	
    }  
    
    while (cases--)  
    {  
	
	cin >> i >> j;  
	
	
	// Scan through the road segment looking for the minimum width. If
	// we hit width = 1, we can stop scanning because its not possible
	// to find a smaller value
	
	min = 3;

	for(i; i<=j; i++){
	    
	    if(road[i] < min){
		
		min = road[i];
	    }
	    
	    if(road[i] == 1){
		    break;
	    }   
	}
	
	cout << min << endl; 	
	
    }  
    
    return 0;  
} 