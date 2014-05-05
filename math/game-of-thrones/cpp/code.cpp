#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;
 
    
int main() {
 

    string item;
    cin >> item;

    int size = item.size();

    // Since there are only 26 possible keys, the fastest structure to
    // use is a map. A map operates in O(log N) time, but because of the low
    // number of keys this is faster than unordered_map's O(N) hash function

    map <char, int> scratch;


    // 1) Iterate through the *first half* of the string. For each character:
    //    a) If the character doesn't exist in the map, add an entry in the map = 1
    //    b) If the character exists in the map, increment its entry by 1
    //
    // 2) Iterate through the map. If there is more than one letter with an 
    //	  ODD number of occurances, the string isn't a palindrome. Otherwise,
    //    its a palindrome.

    for(int i = 0; i < size; i++){

	char letter = item[i];

	if(scratch.count(letter) == 0){

	    scratch[letter] = 1;
	}
	else {

	    scratch[letter]++; 
	}

    }

    bool odd_found = false;
    bool valid = true;

    // "const_iterator" is a special built-in type. 
    // See http://msdn.microsoft.com/en-us/library/0ecs6a5h.aspx

    map<char, int>::const_iterator itr;

    for(itr = scratch.begin(); itr != scratch.end(); itr++) {

	if(itr->second % 2 != 0){
	    
	    if(odd_found){
		
		valid = false;
		break;
	    }
	    else {
		
		odd_found = true;
	    }
	}
    }

    if(valid){
	
	cout << "YES" << endl;
    }
    else {
	
	cout << "NO" << endl;
    }
    
    return 0;
    
}