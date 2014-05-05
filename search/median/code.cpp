#include<iostream>
#include<set>

using namespace std;

int main()
{
    
    int N;	// Number of operations
    char op;	// Operation 'a' to add, 'r' to remove
    int value;	// Value to add or remove

    // @see http://www.cplusplus.com/reference/set/multiset/
    multiset<int> s;
    
    static multiset<int>::iterator it, prev,temp;

    cin >> N;
    
    // This is called a "running median algorithm" or a "streaming median algorithm"
    
    // 1) Load values into a multiset, which has O(log n) searches, adds, and deletes, and
    //    allows multiple instances of the same value
    //
    // 2) When loading the first value, create an iterator pointer that points to the first
    //    element in the set
    //
    // 3) When adding an item to the set
    //    a) if the item added is greater than or equal to the one currently at the pointer, and 
    //	     the set has an even number of elements, move the pointer forward
    //    b) if the item added is smaller than the one currently at the pointer, and the set
    //       has an odd number of elements, move the pointer backwards
    //
    // 4) When removing an item from the set
    //    a) if the item removed is equal to the one currently at the pointer, and the set
    //       has an odd number of elements, move the pointer forward
    //    b) if the item removed is equal to the one currently at the pointer, the set has an
    //       even number of elements, and the item before the pointer isn't equal to the one
    //	     being removed, move the pointer backwards
    //    c) if the item removed is greater than or equal to the one currently at the pointer, 
    //	     and the set has an even number of elements, move the pointer backwards
    //    d) if the item removed is less than or equal to the one currently at the pointer, and 
    //	     the set has an odd number of elements, move the pointer forwards
    
    for(int i = 0; i < N; i++) {

	cin >> op >> value;

	if(op == 'a'){
	    
	    s.insert(value);
	    
	    if(s.size() == 1){
		
		prev = s.begin();
	    }
	    else if( (value >= *prev) && (s.size() % 2 == 0) ){
		
		prev++;
	    }
	    else if( (value < *prev) && (s.size() % 2 != 0) ){
		
		prev--;
	    }
	    
	}         
	else if( (op == 'r') && (s.size() > 0) ){
	    
	    it = s.find(value);
	    
	    if( (it == s.end()) || (*it != value) ){ 
		
		// Trap trying to a) delete from an empty array, or b) trying
		// to delete a nonexistent value from a loaded array
		
		cout << "Wrong!\n"; 
		continue;
	    }
	    else if(*prev == value) {
		
		if(s.size() % 2 != 0){

		    prev++;
		}
		else {

		    temp = prev; 
		    temp--;
		    
		    if(*temp != value){
			
			prev--;
		    }
		}   
	    }
	    else if( (value >= *prev) && (s.size() % 2 == 0) ){
		
		prev--;
	    }
	    else if( (value <= *prev) && (s.size() % 2 != 0) ){
		
		prev++;
	    }
	    
	    s.erase(it); 
	    
	}

	// Print the current median
	
	if(s.size() == 0){
	    
	    // Trap trying to print the median of an empty array
	    
	    cout << "Wrong!\n";
	}
	else if(s.size() % 2 != 0){
	    
	    // If the array has an odd number of elements, we can just print
	    // the value that's at the median pointer. Since its an int, the
	    // output doesn't need to be formatted so we can just use cout <<
	    
	    cout << *prev << endl;
	}
	else {
	    
	    // If the array has an even number of elements, we need to calculate
	    // the average of the value that's at the median pointer and the value
	    // that's before the median pointer
	    
	    long long median = *prev;
	    prev--;
	    median = (median + *prev);

	    // Printing the value is tricky. If it divides evenly, trim the trailing
	    // zero. Otherwise, explicitly print it with a single trailing digit.
	    
	    if(median % 2 == 0){

		printf("%.0lf\n", median/2.);
	    }
	    else{

		printf("%.1lf\n", median/2.);
	    }

	    prev++;
	}
    }


}  