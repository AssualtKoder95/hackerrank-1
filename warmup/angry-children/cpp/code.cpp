
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()  
{          
    int N, K;
    cin >> N >> K;

    // Load the candy packet sizes into a vector object in
    // the supplied order, then sort the contents of the
    // vector object
    
    vector<int> candies;
    candies.assign(N, -1);

    for(int i = 0; i < N; i++){
	
        cin >> candies[i];
    }
    
    sort(candies.begin(), candies.end());
    
    // Initialize to largest value in array (which is the maximum possible delta)
    int best = candies[N - 1];

    // Then slide a K-wide window along the array, looking
    // for the offset with the lowest delta between the first
    // and the last elements. 
    
    for(int i = 0; i <= N - K; i++) {
	
        if(candies[i + K - 1] - candies[i] < best){
	    
            best = candies[i + K - 1] - candies[i];
	}
    }    

    cout << best << endl;

    return 0;

} 