#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int maxBannerHeight(vector<int>& arr) {
    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    
    // dp[d] stores the max height of the taller pillar with a difference of d
    vector<int> dp(total_sum + 1, -1);
    dp[0] = 0; // Base case
    
    for (int x : arr) {
        vector<int> next_dp = dp; // Copy current state
        
        for (int d = 0; d <= total_sum; d++) {
            if (dp[d] == -1) continue;
            
            // Choice 1: Add to the taller pillar
            if (d + x <= total_sum) {
                next_dp[d + x] = max(next_dp[d + x], dp[d] + x);
            }
            
            // Choice 2: Add to the shorter pillar
            if (x <= d) {
                // Shorter pillar stays shorter or becomes exactly equal
                next_dp[d - x] = max(next_dp[d - x], dp[d]);
            } else {
                // Shorter pillar overtakes and becomes the new taller pillar
                next_dp[x - d] = max(next_dp[x - d], dp[d] - d + x);
            }
        }
        dp = next_dp;
    }
    
    return dp[0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << maxBannerHeight(arr) << endl;
    }
    return 0;
}
