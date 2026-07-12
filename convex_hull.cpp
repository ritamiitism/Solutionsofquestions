#include <bits/stdc++.h>

using namespace std;

// Calculates the 2D cross product of vectors AB and AC.
// Returns true if the turn A -> B -> C is clockwise or collinear (<= 0),
// which means the point 'b' should be popped from the convex hull.
bool cross(vector<int>&a, vector<int>&b, vector<int>&c){
    // Cast to long long (1LL) to prevent integer overflow during multiplication 
    // if the coordinate values are large.
    long long cross_product = 1LL * (b[0] - a[0]) * (c[1] - a[1]) - 
                              1LL * (b[1] - a[1]) * (c[0] - a[0]);
    return cross_product <= 0;
}

int main(){
    int t;
    if (!(cin >> t)) return 0;
    
    while(t--){
        int n;
        cin >> n;
        
        // Handle edge case where there are fewer than 3 points
        if (n == 0) continue;
        
        vector<vector<int>> v(n, vector<int>(2));
        for(auto &i: v) cin >> i[0] >> i[1];
        
        // Sorting lexicographically (first by x, then by y) is essential for Monotone Chain
        sort(v.begin(), v.end());
        
        vector<vector<int>> lower, upper;
        
        // Build lower hull
        for(int i = 0; i < n; i++){
            while(lower.size() >= 2 && cross(lower[lower.size()-2], lower[lower.size()-1], v[i])){
                lower.pop_back();
            }
            lower.push_back(v[i]);
        }

        // Build upper hull
        for(int i = n - 1; i >= 0; i--){
            // FIX: Changed v[1] to v[i] here!
            while(upper.size() >= 2 && cross(upper[upper.size()-2], upper[upper.size()-1], v[i])){
                upper.pop_back();
            }
            upper.push_back(v[i]);
        }
        
        // The last point of the lower hull is the first point of the upper hull, and vice versa.
        // We pop them to avoid duplicating the endpoints where the hulls meet.
        if(lower.size() > 0) lower.pop_back();
        if(upper.size() > 0) upper.pop_back();
        
        // Print the full convex hull
        for(auto &i: lower) cout << i[0] << " " << i[1] << endl;
        for(auto &i: upper) cout << i[0] << " " << i[1] << endl;
    }
    
    return 0;
}
