#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;



int main()  
{      
    
    // This problem is relatively easy to solve because the pairs
    // only span a single dimension. For the "find closest points in
    // X/Y or X/Y/Z, serious math is required. 
    // See http://en.wikipedia.org/wiki/Closest_pair_of_points
    
    
    int length;

    cin >> length;

    // 1) Load all the items into a vector and sort it in ascending
    // order, which places points that are numerically close to each
    // other in physical proximity to each other in the array
    //
    // 2) Scan through the array comparing the current point to the
    // one next in line. 
    //	    a) If the difference is *less than* the current best distance, 
    //	    clear the solution array and add the two points to the solution
    //	    array
    //	    b) If the difference is *equal to* the current best distance, 
    //	    add the two points to the solution array    
    //
    // 3) Sort the solution array in ascending order, and dump it to the console
    
    vector<long> items;
    vector<long> result;
    long point;
    long best;

    for(int i = 0; i < length; i++){

	cin >> point;
	items.push_back(point);
    }
    
    sort(items.begin(), items.end());
    
    // Prime the system
    
    best = abs(items[0] - items[1]);
    result.push_back(items[0]);
    result.push_back(items[1]);    
    
    for(int i = 1; i < length - 1; i++){

	long delta = abs(items[i] - items[i+1]);
	
	if(delta == best){
	    
	    result.push_back(items[i]);
	    result.push_back(items[i + 1]); 	    
	}
	else if(delta < best){
	    
	    best = delta;
	    result.clear();
	    result.push_back(items[i]);
	    result.push_back(items[i + 1]); 	    
	}	
    }    
    
    sort(result.begin(), result.end());

    length = result.size();
    
    for(int i = 0; i < length; i++){

	cout << result[i] << " ";
    }

    return 0;

} 