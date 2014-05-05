#include <cstdio>
#include <iostream>

using namespace std;
 
    
int main() {
 
    // Get total number of testcases
    int total_items;
    cin >> total_items;
   
    // Iterate through each testcase
    for(int i = 0; i < total_items; i++){
	
	int Px,Py,Qx,Qy;
	int Dx, Dy;
	
	cin >> Px >> Py >> Qx >> Qy;
	
	Dx = Qx - Px;
	Dy = Qy - Py;
	
	cout << (Qx + Dx) << " " << (Qy + Dy) << endl;	
	
    }
    
}