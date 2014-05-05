#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;

int main()  
{      
      
    // This is a classic lookup table or hash table problem. 
    //
    // 1) Iterate through all the first table's items, creating a LUT
    //    entry with +1 for unique items or incrementing an item's entry
    //    if it already exists in the map
    //
    // 2) Iterate through all the second table's items, creating a LUT
    //    entry with -1 for unique items or decrementing an item's entry
    //    if it already exists in the map  
    //
    // 3) Iterate through the LUT and output all entries with a negative value
    
    map <int, int> scratch;

    int length;
    cin >> length;
    
    for(int i = 0; i < length; i++){

	int item;
	cin >> item;
	
	if(scratch.count(item) == 0){

	    scratch[item] = 1;
	}
	else {

	    scratch[item]++; 
	}
    }
    
    cin >> length;
    
    for(int i = 0; i < length; i++){

	int item;
	cin >> item;
	
	if(scratch.count(item) == 0){

	    scratch[item] = -1;
	}
	else {

	    scratch[item]--; 
	}
    }

    // "const_iterator" is a special built-in type. 
    // See http://msdn.microsoft.com/en-us/library/0ecs6a5h.aspx
    
    map<int, int>::const_iterator itr;
     
    for(itr = scratch.begin(); itr != scratch.end(); itr++) {

	if(itr->second < 0){
	    
	    cout << itr->first << " ";
	}
    }
    
    return 0;

} 