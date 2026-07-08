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
int ans;
int n;

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
    //  Recursive DP     dp[idx][difference]
    int pillarSum = accumulate(pillars.begin(), pillars.end(), 0);
    dp.assign(n, vector<int>(pillarSum+1, -1));
    cout<<dpApproach(0, 0, 0)/2<<"\n";
}

int main(){
    int t;
    t=1;
    // cin>>t;

    while(t--){
        solve();
    }
    return 0;
}