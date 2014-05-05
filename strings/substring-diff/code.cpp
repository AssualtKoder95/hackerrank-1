#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int num_cases;
    int k;
    string string1;
    string string2;
    
    cin >> num_cases;
    
    for(int x = 0; x < num_cases; x++){
	
	cin >> k >> string1 >> string2;

	int length = string1.size();
	
	
	// Dynamically allocate the diff array based on the length of the input string. Although
	// its possible to create an array of pointers to arrays to get the 2D effect, it uses
	// a lot of resources. A much cleaner solution is to allocate a single strip of memory
	// that's X * Y bytes long, then access it as X + [Y * size_y]
	
	// @see http://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
	
	int size_x = length;
	int size_y = length;
	
	bool* diff_array = new bool[size_x * size_y];

	// Diff every character in string_1 against every character in string_2. This 
	// immediately costs us O(N^2), and its only practical for short strings. A 1MB
	// string against a 1MB string would consume 1TB of memory.
	
        for(int i = 0; i < length; i++){
	    
            for(int j = 0; j < length; j++){
		
                diff_array[i + (j * size_y)] = (string1[i] != string2[j]);
	    }
        }
	
        int front_pointer,back_ptr1,back_ptr2,front_sum1,front_sum2,back_sum1,back_sum2;
	int curr_max = -1;
	
	// @see http://www.quora.com/What-is-the-algorithmic-approach-to-solve-hackerrank-problem-Substring-Diff?share=1
        for(int i = 0; i < length; i++){
	    
            front_sum1 = front_sum2 = back_sum1 = back_sum2 = 0;
            back_ptr1 = back_ptr2 = -1;
	    
            for(front_pointer = 0; front_pointer + i < length; front_pointer++){
		
                front_sum1 += diff_array[front_pointer + ((i + front_pointer) * size_y)]; // diff_array[front_pointer][i+front_pointer];
                front_sum2 += diff_array[(i + front_pointer) + (front_pointer * size_y)]; // diff_array[i+front_pointer][front_pointer];
		
                while(front_sum1 - back_sum1 > k){
		    
                    back_ptr1++;
                    back_sum1 += diff_array[back_ptr1 + ((i+back_ptr1) * size_y)]; // diff_array[back_ptr1][i+back_ptr1];
                }
		
                while(front_sum2 - back_sum2 > k){
		    
                    back_ptr2++;
                    back_sum2 += diff_array[(i + back_ptr2) + (back_ptr2 * size_y)]; // diff_array[i+back_ptr2][back_ptr2];
                }

                if(front_pointer - back_ptr1 > curr_max){
		    
                    curr_max = front_pointer - back_ptr1;
		}
		
                if(front_pointer - back_ptr2 > curr_max){
		    
                    curr_max = front_pointer - back_ptr2;
		}
            }
        }

	cout << curr_max << endl;
	
	delete [] diff_array;
    }
    
    return 0;
}