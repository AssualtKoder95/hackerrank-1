
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>

using namespace std;

int main()  
{      
    
    int total;
    vector<int> items;
    
    cin >> total;
    
    // Handle the case of a single number
    if(total == 1){
	
	int temp;
	cin >> temp;
	cout << temp;
	
	return 0;
    }

    // Load all the ints into the array, then sort
    // it in ascending order
    
    items.assign(total, -1);
    
    for(int i = 0; i < total; i++){

	cin >> items[i];
    }	
    
    sort(items.begin(), items.end());
    
    // Iterate through the sorted array 
    
    int target = 0;
    
    for(int i = 0; i < total; i+=2){
	
	if(items[i] != items[i+1]){
	    
	    // CASE 1: The first pair of cells don't match. The only way this 
	    // is possible is if the unique item is in the first cell.
	    
	    if(i == 0){
		
		target = items[i];
	    }
	    
	    // CASE 2: The final pair of cells don't match. The only way this 
	    // is possible is if the unique item is in the last cell.
	    
	    else if(i == total-1){
		
		target = items[i];
	    }
	    
	    // CASE 3: If the first item in the pair doesn't match the item
	    // before it, then this is the unique item
	    
	    else if(items[i] != items[i-1]){
		
		target = items[i];
	    }
	    
	    // CASE 4: Otherwise, its the final item in the pair
	    
	    else {
		
		target = items[i];
		
	    }
	    
	    break;
	}

    }
    
   cout << target << endl;

    
    return 0;  
} 