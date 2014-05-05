
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    // Load each individual testcase
    
    while (t--) {
	
	int n;
	cin >> n;
	
	int a[50000];
	
	// Load the list of cards for the testcase, then sort the list
	// by the cards' face value
	
	for (int i = 0; i < n; i++){
	    
	    cin >> a[i];
	}
	
	sort(a, a + n);
	
	// Place a marker on the first card, then iterate through
	// the array of cards
	
	int marker = 0;	
	long long result = 1;
	
	for (int i = 0; i < n; i++){
	    
	    // Move the marker forwards until we reach the end of the array,
	    // or we reach a card with a face value that exceeds the current
	    // number of cards we've processed.
	    
	    while ( (marker < n) && (a[marker] <= i) ){
		
		marker++;
	    }
	    	    
	    if (marker > i){
		
		// If the point where the marker lands is greater than the 
		// current array index we're processing, there are (i - marker)
		// cards ahead of it that we can pick. Multiply the result by this
		// number, and MOD it to keep result from overflowing. What we're
		// actually doing here is calculating nPr for the number of cards
		// that we can choose from ahead of the index. This is equal to n!, and
		// successive passes through the remaining cards as we advance i calculate
		// the factorial.
		
		result = (result * (marker - i)) % 1000000007;
	    }
	    else {
		
		// If the point where the marker lands is equal to or less than the
		// current index, we're blocked. There's no solution.
		
		result = 0;
		break;
	    }
	}
	
	cout << result << endl;
	
    }
    
    return 0;
}