
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main()  
{      
    
    int cases, keys;
    unsigned long delta;
    bool valid;
    
    // Store arrays as vectors so they can be sorted and resized
    
    vector<unsigned long> a;
    vector<unsigned long> b;
    
    cin >> cases;
    
    while(cases--){
	
	cin >> keys >> delta;
	
	// Set arrays to size of test case, then load-in each
	// array's line of values
	
	a.assign(keys, -1);
	b.assign(keys, -1);

	for(int i = 0; i < keys; i++){

	    cin >> a[i];
	}
	
	for(int i = 0; i < keys; i++){

	    cin >> b[i];
	}	

	// Sort one array in ascending order, and the other array
	// in descending order
	
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	
	// Iterate through the arrays adding keys at the same index
	// together. If a pair of keys doesn't add up to the
	// specified delta, the arrays aren't valid, so we can quit.
	
	valid = true;

	for(int i = 0; i < keys; i++) {
	    
	    if(a[i] + b[i] < delta){

		valid = false;
		break;
	    }
	}  
	
	if(valid){
	    cout << "YES";
	}
	else {
	    cout << "NO";
	}

	cout << endl;
    }

    return 0;

} 