
#include <string>
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <vector>


using namespace std;

int main()  
{      
    
    string buffer;

    cin >> buffer;
    
    // Calculate the height and width of the grid using
    // the formula provided
    
    int length = buffer.length();

    int width = floor(sqrt(length));
    int height = ceil(sqrt(length));
    
    // Then just shift forward by a small offset, then make multiple large 
    // jumps forward to simulate the "columns". The complicated test condition
    // in the loop is needed to handle perfect squares
    
    for(int i = 0; ((i < width) || ((i == width) && (width != height)) ); i++){
	
	for(int j = 0; j <= height; j++){

	    int offset = i + (j * height);
	    
	    if(offset < length){
		cout << buffer[i + (j * height)];
	    }
	}
	
	cout << " ";
	
    }

    return 0;  
} 