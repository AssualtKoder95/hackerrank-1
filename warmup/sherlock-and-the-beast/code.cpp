
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <map>  

using namespace std;

int main()  
{      
    
    int cases, digits, fives, threes, remainder;

    cin >> cases;

    while (cases--)  
    {  
	
	cin >> digits;	
	
	if(digits < 9){
	    
	    switch(digits){
		
		case 3 : { cout << "555"; break;}
		case 5 : { cout << "33333"; break;}
		case 6 : { cout << "555555"; break;}
		case 8 : { cout << "55533333"; break;}
		default: { cout << "-1";}
	    }
	    
	}
	else {
	
		remainder = digits - 9;
		
		switch(remainder % 3){

		    case 0 : { threes = 0; break;}
		    case 1 : { threes = 10; break;}
		    case 2 : { threes = 5; break;}
		}
		
		fives = digits - threes;

		for(int i = 0; i < digits; i++){

		    if(i < fives){

			cout << 5;
		    }
		    else {
			cout << 3;
		    }
		} 
	}
	
	cout << endl; 
	
    }  
    
    return 0;  
} 