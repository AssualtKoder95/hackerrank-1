
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()  
{      
    int items, total = 0;
    unsigned long money;
    
    // Store arrays as vectors so they can be sorted and resized
    vector<unsigned long> a;
    
    cin >> items >> money;
    
    // Load item values into array, then sort in ascending order
    
    a.assign(items, -1);

    for(int i = 0; i < items; i++){

	cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    
    // Iterate through the array subtracting the value of the current item
    // from money until the current item can't be bought
    
    for(int i = 0; i < items - 1; i++){

	if(money >= a[i]){
	    
	    total++;
	    money -= a[i];
	}
	else {
	    
	    break;
	}
	
    }
    
    cout << total << endl;

    return 0;

} 