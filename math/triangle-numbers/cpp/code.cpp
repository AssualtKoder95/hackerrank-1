
#include <iostream>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    // Load each individual testcase
    
    while (t--) {
	
	long n;
	cin >> n;
	
	
	// This challenge is just a trivial numeric progression. If you write out
	// the series to 10 or so rows, the pattern becomes obvious.
	
	if(n % 2 != 0){
	
	    cout << 2 << endl;
	}
	else {
	    
	    if( (n / 2) % 2 == 0){
		
		cout << 3 << endl;
	    }
	    else {
		
		cout << 4 << endl;
	    }	    
	}
	
    }
    
    return 0;
}