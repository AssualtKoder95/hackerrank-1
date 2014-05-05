
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    
    // 1) Store the items as an unordered_map, which is a form of hash table, allowing
    // lookups in constant time. 
    //
    // 2) Use the item's "value" as both the "key" and the "value" in the hash table. This
    // lets us iterate through the table and extract the original values. This avoids having
    // to use two tables, saving lots of memory and potentially having the entire tabe fit
    // in the CPU cache.
    //
    // 3) Iterate through each entry in the table and read its *value*. If a *key* exists
    // in the table which is equal to value - K, then a pair of numbers exists with difference
    // equal to K, so increment the pair counter.
    //
    // 4) Write the value of the pair counter to console.
    
    
    int N; // Number of items
    int K; // Difference between items
    int item;
    int matches = 0;

    cin >> N >> K;
    
    // @see http://www.cplusplus.com/reference/unordered_map/unordered_map/
    unordered_map <int, int> scratch;   
    
    for (int i = 0; i < N; ++i) {
	cin >> item;
	scratch[item] = item;
    }
    
    // "const_iterator" is a special built-in type. 
    // See http://msdn.microsoft.com/en-us/library/0ecs6a5h.aspx
    
    unordered_map<int, int>::const_iterator itr;
     
    for(itr = scratch.begin(); itr != scratch.end(); itr++) {

	if(scratch.count(itr->second - K) > 0){
	    matches++;
	}
    }  

    cout << matches << endl;
      
    return 0;
}