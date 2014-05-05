
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>

using namespace std;

int main()  
{      
    
    int total, friends;
    vector<unsigned long> flowers;
    
    unsigned long multiplier = 1;
    unsigned long cost = 0;    

    cin >> total >> friends;

    // Load all the flower proces into the array, then sort
    // it in descending order, allowing us to but the most
    // expensive flowers first
    
    flowers.assign(total, -1);
    
    for(int i = 0; i < total; i++){

	cin >> flowers[i];
    }	
    
    sort(flowers.rbegin(), flowers.rend());
    
    // Iterate through the sorted array of flower prices, multiplying
    // the price by the multiplier (which is initially 1). Every time
    // (loop_index MOD friend_count) equals zero, increment the multiplier
    // by one.
    
    for(int i = 0; i < total; i++){
	
	if(i && (i% friends == 0)){
	    
	    multiplier++;
	}
	
	cost += flowers[i] * multiplier;
    }
    
    cout << cost << endl;

    
    return 0;  
} 