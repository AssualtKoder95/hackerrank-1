#include <iostream>

using namespace std;

int tree[1 << 15];
int cache[1 << 15];
int numbers[15];
int n;

int solve(int node) {
    
    
    // If a node has been explored, return the result of that
    // exploration: 0 for unsafe, 1 for safe.
    
    if (tree[node] != -1){
	
	return tree[node];
    }
    else {

	// Otherwise, mark this node as unsafe
	tree[node] = 0;

	// And iterate through all its children
	for (int i = 0; i < n; i++){

	    int not_leaf_node = node & (1 << i);
	    
	    // If the node isn't a leaf node, iterate through that node's children
	    if (not_leaf_node){

		// If the leaf node at the end of the recursion is unsafe, we've found
		// a valid walk. 
		
		if ( solve(node - (1 << i)) == 0){

		    tree[node] = 1;
		    break;
		}
	    }
	}
    }
    
    return tree[node];
    
}

int main() {
    
    int t;
    cin >> t;
    
    // Load in the testcases
    
    while (t--){
		
	cin >> n;
	
	// Load in the number sequence. There are 15 numbers, giving nPr(15,14)
	// so 1,307,674,368,000 possibilities if we use exhaustive search, which
	// would take over an hour to compute.
	
	for (int i = 0; i < n; i++){
	    
	    cin >> numbers[i];
	}
	
	// Initialize the first cell in the tree and cache arrays
	tree[0] = 0;
	cache[0] = 0;
	
	// Iterate through each number in the sequence, creating a binary tree
	// representing the outcome of deleting the current node in the sequence
	// @see http://en.wikipedia.org/wiki/Binary_tree
	
	for (int i = 0; i < n; i++) {
	    
	    // Calculate 2^i using a left shift operation	    
	    int offset = (1 << i);
	    
	    for (int j = 0; j < offset; j++){
			
		if ( (tree[j] == 0) && (numbers[i] > cache[j]) ){
		    
		    // If this node's parent is unsafe, and deleting this node would
		    // create an increasing sequence, mark this node as unsafe	
		    
		    tree[offset + j] = 0;		    
		}
		else {
		    
		    // Otherwise mark it as unexplored  
		    tree[offset + j] = -1;
		}
		
		// Write the current node's value to the cache tree
		cache[offset + j] = numbers[i];
		
	    }
	}
	
	
	// Recursively solve the tree
	
	bool alice_wins = solve((1 << n) - 1);

	if(alice_wins){
	    
	    cout << "Alice" << endl;
	}
	else {
	    
	    cout << "Bob" << endl;
	}
	
    }
    
    return 0;
}