#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/**
 * Performs a recursive depth-first search of every possible walk through the game board,
 * up to a depth of K steps. Results are returned in &chk, mapped as X Y coordinates with
 * number of moves required to solve as the value, or INT_MAX if unsolvable.
 * 
 * @param board - Vector containing all of the squares on the board, represented as strings
 * @param chk - Vector containing cell solutions
 * @param row - Current row
 * @param col - Current column
 * @param steps - Current step
 * @param K - Maximum number of steps
 * @param changes - Number of changes required to reach current state
*/

void depth_first_search(vector<string> &board, vector<vector<int> > &chk, int row, int col, int steps, int K, int changes) {
    
    if (row >= 0 
	&& row < board.size() 
	&& col >= 0 
	&& col < board[0].size() 
	&& steps <= K 
	&& changes < chk[row][col]) {
	
        chk[row][col] = changes;
	
        depth_first_search(board, chk, row - 1, col, steps + 1, K, changes + (board[row][col] != 'U'));
        depth_first_search(board, chk, row + 1, col, steps + 1, K, changes + (board[row][col] != 'D'));
        depth_first_search(board, chk, row, col - 1, steps + 1, K, changes + (board[row][col] != 'L'));
        depth_first_search(board, chk, row, col + 1,steps + 1, K, changes + (board[row][col] != 'R'));
    }
}
 

int main() {
    
    int N; // Number of lines of letters
    int M; // Number of letters per line
    int K; // Number of time ticks
    
    string item;
    
    cin >> N >> M >> K;
    
    // Create a 1-D vector of N strings describing each row of the board,
    // and pre-load it with the empty string
    
    vector<string> board(N, "");   
    
    // Create a 2-D vector N rows by M columns, and pre-load each
    // column with the platform's maximum integer value
    
    vector<vector<int> > chk (N, vector<int> (M, INT_MAX));

    for (int i = 0; i < N; ++i) {
	cin >> item;
	board[i] = item;
    }
    
    // Solve the board
    depth_first_search(board, chk, 0, 0, 0, K, 0);
    
    // @see http://www.cplusplus.com/reference/utility/pair/
    pair<int, int> target;
    
    // Iterate through each item in the solution array to find
    // the *, then extract its solution as a pair
    
    for(int i = 0; i < board.size(); ++i){
	
        for (int j = 0; j < board[i].size(); ++j){
	    
            if (board[i][j] == '*'){
	
                target = make_pair(i, j);
	    }
	}
    }
    
    // If the number of moves required to solve is INT_MAX, its
    // unsolvable, so return -1. Otherwise, return the number of moves.
    
    if(chk[target.first][target.second] == INT_MAX){ 
	
	cout << -1 << endl;
    }
    else {
	
	cout << chk[target.first][target.second] << endl;
    }
    
    return 0;
}