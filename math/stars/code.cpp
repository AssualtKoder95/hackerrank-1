#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

double x[100];
double y[100];
int w[100];

int main() {

    int n;
    cin >> n;
    
    vector<pair<double, double> >p;
    

    // Jitter all the points, creating 4 instances of each point translated
    // right-up, right-down, left-up, left-down by a tiny amount (1e-5). This
    // handles the broken unit test cases where a star lands ON a line between
    // two other stars, creating an unsolvable system.
    
    for (int i = 0; i < n; i++) {

	cin >> x[i] >> y[i] >> w[i];

	p.push_back(make_pair(x[i] - 1e-5, y[i] - 1e-5));
	p.push_back(make_pair(x[i] - 1e-5, y[i] + 1e-5));	
	p.push_back(make_pair(x[i] + 1e-5, y[i] - 1e-5));
	p.push_back(make_pair(x[i] + 1e-5, y[i] + 1e-5));
	
    }


    int ans = 0;
    int cnt1, cnt2;
    double dx1, dx2, dy1, dy2;

    // Iterate through every possible pair of points. Since the relationship isn't 
    // directional (Picking stars #47 and #63 is the same as picking stars #63 and #47),
    // we use two loops, one iterating the array from left to right, and an inner loop
    // iterating the array from (current index + 1) to right. This improves speed
    // from O(N^3) to O((N^2)*(N/2)) 
    
    for (int i = 0; i < p.size(); i++) {

	for (int j = i + 1; j < p.size(); j++) {

	    cnt1 = 0;
	    cnt2 = 0;
	    
	    // In geometry, two points define a line, and a line is really just a slope,
	    // which means for a given X, point Y on the line is just (slope * X). Using
	    // this observation, we can extend the line to infinity and determine whether
	    // any point is above or below the line.
	    
	    dx1 = p[j].first - p[i].first;
	    dy1 = p[j].second - p[i].second;

	    // Iterate through all points, determining which side of the line they fall
	    // on and summing the weight of the stars on each side. Of the two groups, pick
	    // the smaller one, and of all star pairs, pick the maximum.
	    
	    for (int k = 0; k < n; k++) {

		dx2 = x[k] - p[i].first;
		dy2 = y[k] - p[i].second;

		if (dx1 * dy2 - dx2 * dy1 > 0.0){
		    
		    cnt1 += w[k];
		}
		else {
		    
		    cnt2 += w[k];
		}

	    }

	    ans = max(ans, min(cnt1, cnt2));

	}

    }

    cout << ans << endl;
    
    return 0;
  
}