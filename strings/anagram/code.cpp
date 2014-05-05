#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;
 
    
int main() {
 
    // Get total number of testcases
    int total_items;
    cin >> total_items;
   
    // Iterate through each testcase
    for(int i = 0; i < total_items; i++){
	
	string item;
	cin >> item;
	
	int size = item.size();
	
	// If the length of the string isn't evenly divisible by two, the substrings
	// are different lengths, so we fail the testcase
	
	if( size % 2 != 0){
	    
	    cout << -1 << endl;
	    continue;
	}
		
	// Since there are only 26 possible keys, the fastest structure to
	// use is a map. A map operates in O(log N) time, but because of the low
	// number of keys this is faster than unordered_map's O(N) hash function
	
	map <char, int> scratch;
	
	int midpoint = size / 2;
	
	
	// 1) Iterate through the *first half* of the string. For each character:
	//    a) If the character doesn't exist in the map, add an entry in the map = 1
	//    b) If the character exists in the map, increment its entry by 1
	//
	// 2) Iterate through the *second half* of the string. For each character:
	//    a) If the character exists in the map, decrement its entry by 1
	//    b) If the character doesn't exist in the map, add an entry in the map = -1
	//
	// 3) Iterate through the map. Sum the absolute value of all the entries and divide
	//    it by 2, which gives the total number of changes required to make the first 
	//    string into the second string
	
	for(int i = 0; i < size; i++){

	    char letter = item[i];
	    
	    if( i < midpoint){
		
		if(scratch.count(letter) == 0){

		    scratch[letter] = 1;
		}
		else {

		    scratch[letter]++; 
		}
	    }
	    else {
		
		if(scratch.count(letter) == 0){

		    scratch[letter] = -1;
		}
		else {

		    scratch[letter]--; 
		}			
	    }
	}
	
	int total = 0;
	
	// "const_iterator" is a special built-in type. 
	// See http://msdn.microsoft.com/en-us/library/0ecs6a5h.aspx

	map<char, int>::const_iterator itr;

	for(itr = scratch.begin(); itr != scratch.end(); itr++) {

	    total += abs(itr->second);
	}

	cout << total/2 << endl;	
	
    }
    
}