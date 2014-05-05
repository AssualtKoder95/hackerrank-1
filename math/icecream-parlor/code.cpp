#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// a) The "naive" solution is to compare each item against each other item in the
//    array, giving O(N^2)/2 time
//
// b) The "improved" solution is to sort the array by value, then use binary search
//    giving O(N log(N)) time
//
// c) The "optimal" solution is to store the costs as map keys, and store the index 
//    of all matching flavours for a given cost inside a vector within the map
//    element. This handles collisions, and works in O(N log N) time (because C++
//    stores the map in sorted form)
//
// d) The "show off" solution is to store the costs as hashed map keys, and then store
//    the unhashed costs as a vector (to handle hash collisions), and within each vector
//    element, store the indices of all matching flavours for a given cost. This works 
//    in O(N) time, but is way too much work for a 30 point problem.


struct Flavour
{   
   int cost;
   vector<int> items;
}; 

int main() {
 
    // Get total number of testcases
    int total_items;
    cin >> total_items;
   
    // Iterate through each testcase
    for(int i = 0; i < total_items; i++){
	
	int budget;
	cin >> budget;
	
	int total_flavours;
	cin >> total_flavours;	
	    
	// @see http://www.cplusplus.com/reference/unordered_map/unordered_map/
	map <int, Flavour> scratch;   

	for (int j = 0; j < total_flavours; j++) {
	    
	    int cost;
	    cin >> cost;

	    // If this is the first time we've seen a flavour at this cost,
	    // create a new node for it
	    
	    if(scratch.count(cost) == 0){
		
		Flavour new_cost;
		
		new_cost.cost = cost;
		
		vector<int> items;
		items.push_back(j);
		new_cost.items = items;
		
		scratch[cost] = new_cost;
	    }
	    
	    // If one or more flavours already exist at this cost, add this flavour
	    // to the node's list of items
	    
	    else {
		
		Flavour existing_cost = scratch[cost];

		existing_cost.items.push_back(j);	
		scratch[cost] = existing_cost;				
	    }	    
	    
	}

	// "const_iterator" is a special built-in type. 
	// See http://msdn.microsoft.com/en-us/library/0ecs6a5h.aspx

	map<int, Flavour>::const_iterator itr;
	vector<int> result;

	for(itr = scratch.begin(); itr != scratch.end(); itr++) {

	    Flavour primary = itr->second;
	    
	    // CASE 1: If the two flavours have the same cost, and the cost of each flavour
	    // is equal to exactly half of the budget
	    
	    if( (primary.cost == (budget / 2)) && (primary.items.size() > 1) ){
		
		// The test cases expect the results to be sorted, so we put them into
		// a vector container, sort them, and print them
		
		result.push_back(primary.items[0] + 1);
		result.push_back(primary.items[1] + 1);
		
		sort(result.begin(), result.end());
		
		cout << (result[0]) << " " << (result[1]) << endl;
		
		break;
	    }
	    
	    // CASE 2: A flavour exists in the table that, when added to the cost of the
	    // flavour we're currently examining, adds up to the budget
	    
	    else {
			
		int search_cost = budget - primary.cost;
		
		if(scratch.count(search_cost) > 0){
		    
		    Flavour secondary = scratch[search_cost];
		    
		    // The test cases expect the results to be sorted, so we put them into
		    // a vector container, sort them, and print them
		    
		    result.push_back(primary.items[0] + 1);
		    result.push_back(secondary.items[0] + 1);

		    sort(result.begin(), result.end());

		    cout << (result[0]) << " " << (result[1]) << endl;	

		    break;		    
		    		
		}
		
	    }
	    
	    // Otherwise, keep iterating through flavours

	} 	
	
	
    }
    
    return 0;
    
}