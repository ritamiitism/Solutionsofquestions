/*
You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner 
standing on top of TWO PILLERS.
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height
of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2.
In case, there is no combination possible, print 0.

INPUT :
1
5
1 2 3 4 6
Output :
8
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pillars;
vector<bool> vis;
int ans;
int n;

void maxHeight(int idx, int p1, int p2){
    if(idx == n){
        if(p1 == p2){
            ans = max(ans, p1);
        }
        return;
    }
    maxHeight(idx+1, p1+pillars[idx], p2);  // add this on pillar 1
    maxHeight(idx+1, p1, p2+pillars[idx]);  // add this on pillar 2
    maxHeight(idx+1, p1, p2);             // skip this pillar
}

vector<vector<int>> dp;    //dp[idx][diff]
int dpApproach(int idx, int p1, int p2){
    if(idx == n){
        if(p1 == p2){
            return 0;
        }else {
            return -1e8;
        }
    }
    if(dp[idx][abs(p1-p2)] != -1) return dp[idx][abs(p1-p2)];

    // If we place the current pillar on either pillar, that rod becomes part of the final solution.
    // our function returns the total length of the pillar which are used to make p1==p2 at last
    // so our final pillar length required is ***dpApproach(0,0,0) / 2***
    int t1 = pillars[idx]+dpApproach(idx+1, p1+pillars[idx], p2);  // add this on pillar 1
    int t2 = pillars[idx]+dpApproach(idx+1, p1, p2+pillars[idx]);  // add this on pillar 2
    int t3 = dpApproach(idx+1, p1, p2);             // skip this pillar
 
    return dp[idx][abs(p1-p2)] = max({t1, t2, t3});
}

void solve(){
    cin>>n;
    
    pillars.assign(n, 0);
    for(int i=0; i<n; i++){
        cin>>pillars[i];
    }

    // Recursive Approach   // T.C. :-  O(3^n)
    ans = 0;
    maxHeight(0,0,0);
    cout<<ans<<'\n';
    
    //  Recursive DP     dp[idx][difference]
    int pillarSum = accumulate(pillars.begin(), pillars.end(), 0);
    dp.assign(n, vector<int>(pillarSum+1, -1));
    cout<<dpApproach(0, 0, 0)/2<<"\n";

    //  Tabulation DP
    // Time Complexity : O(n × maxPillarSum)
    vector<int> dp1D(pillarSum+1, -1);
    // dp1D[d] = the maximum possible height of the shorter pillar when the difference between the two pillars is d.
    dp1D[0] = 0;

    //  dp1D[3] = 10,  means
    // Shorter pillar = 10, Difference = 3, Taller pillar  = 13
    // Notice that we never store the taller pillar because it is simply (taller = shorter + difference)

    for(int i=0; i<n; i++){
        vector<int> nextDp = dp1D;

        for(int d=0; d<=pillarSum; d++){
            if(dp1D[d] == -1)  continue;

            // Put the current pillar on Taller pillar
            if(d + pillars[i] <= pillarSum){
                int newDiff = d + pillars[i];
                nextDp[newDiff] = max(nextDp[newDiff], dp1D[d]);  // current shorter -> dp1D[d]
            }

            // Put the current pillar on Shorter pillar
            int newDiff = abs(d - pillars[i]);
            int newShorter = dp1D[d] + min(d, pillars[i]);
            nextDp[newDiff] = max(nextDp[newDiff], newShorter);
        }
        dp1D = nextDp;
    }
    cout<<dp1D[0]<<'\n';

}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}