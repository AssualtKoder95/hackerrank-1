
// Not sure if its the author's intent for the question to be
// *quite* so easy, but all you have to do is keep a running
// total of the number of candies added, then divide it by the
// number of jars
 
#include <iostream>    

using namespace std;

int main(){      
    
    long jars, cases, start, end, candies;
    unsigned long long total = 0;
    
    cin >> jars >> cases;

    while (cases--){  

	cin >> start >> end >> candies;	
	total += ((end - start) + 1) * candies;
    }  
    
    cout << total / jars << endl; 
    
    return 0;  
} 