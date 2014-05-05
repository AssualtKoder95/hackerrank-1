
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    // Load each individual testcase
    
    while (t--) {
	
	long n;
	cin >> n;
	
	// Create an array to hold counts from 0 to 9 (even though we don't 
	// actually use zero) and initialize all the cells to zero.
	
	int digit_counts[10];
	
	for(int i = 0; i <= 9; i++){
	    
	    digit_counts[i] = 0;
	}
	
	// Convert the number to a string, then iterate through it counting
	// the number of times each digit occurs
	
	string digits = to_string(n);
	
	for(auto itr = digits.begin(); itr != digits.end(); itr++) {

	    // The characters in the string are stored as ASCII. For example,
	    // "1" in ASCII is (int)49. Convert them back to ints by subtracting
	    // 48. If we had to do this with multi-digit numbers, the easiest
	    // way is to use sstream. @see http://www.cplusplus.com/reference/sstream/stringstream/
	    
	    int idx = *itr - 48;	    
	    digit_counts[idx]++;

	} 

	// Check for divisibility by 1 through 9. If divisible, add the count
	// of that number to the total
	
	int result = 0;
	
	for(int i = 1; i <= 9; i++){

	    if(n % i == 0){
		
		result += digit_counts[i];
	    }
	    
	}
	
	cout << result << endl;
	
    }
    
    return 0;
}