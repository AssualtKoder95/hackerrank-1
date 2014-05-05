

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

 
int main()  
{      
    
    int length;
    cin >> length;

    // Create an array of strings to serve as the "sorting bins"
    // ================================================================
    
    int bin_count = 100;
    string* bins = new string[bin_count];   

   
    // Drop words into bins based on the supplied key. When
    // multiple words have to be stored in a bin, simply concatenate
    // them with spaces
    // ======================================================
    
    int key_val;
    string word;
    
    for(int i = 0; i < length; i++){

	cin >> key_val >> word;
	
	if( i < length/2){
	    
	    word = '-';
	}

	if(bins[key_val] == ""){
		
		bins[key_val] = word + " ";
	}
	else {
		bins[key_val] += word + " ";
	}
    } 
   
    
    // Traverse the contents of the bins, printing the,
    // ================================================================ 

    string output;
    
    for(int k = 0; k < bin_count; k++){
 	
	output +=  bins[k];	
    }

    cout << output << endl;    

    return 0;
    
} 