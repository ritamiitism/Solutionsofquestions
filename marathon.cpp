/*
A person is running a marathon of distance D with limited energy H.
He can change his pace every 1 km. Every pace consumes some amount of energy.
Given 5 paces in increasing order of time, i.e. time taken to run 1 km and energy consumed in 1km.
You need to find the least amount of time required to complete the marathon within the given amount of energy.
Paces are given such that the combination always completes the marathon.

Input format:
The first line contains the number of test cases T.
Each test case is given as follows:
- The first line of each test case contains the 2 integers D and H (D is the distance and H is the energy)
- The next 5 lines are as follows:
- There are 3 integers (M, S and E) where: M is the minutes and S is the seconds required to run 1 km
      and E is the energy consumed in 1 km.

Output Format:
Print the following:
# followed by test case number followed by minimum time in minutes followed by seconds
Eg: #1 153 20

Eg: D = 30, H = 130
5 Paces: (M min S sec E energy)
4 50 7
5 0 5
5 10 4
5 20 3
5 30 2

Output: #1 153 20
*/

#include <bits/stdc++.h>
using namespace std;

struct Metric{
    int m, s, e;
};
vector<Metric> arr;

vector<vector<int>> dp;
int marathon(int dist, int energy){
    if(energy < 0) return 1e8;
    if(dist == 0){
        return 0;
    }
    if(dp[dist][energy] != -1) return dp[dist][energy];

    int time = 1e8;
    for(int i=0; i<5; i++){
        time = min(time, arr[i].m*60 + arr[i].s + marathon(dist-1, energy-arr[i].e));
    }
    return dp[dist][energy] = time;
}

vector<vector<vector<int>>> dp_3d;
int minTimeReq(int dist, int energy, int idx){
    if(energy < 0) return 1e8;
    if(idx == 5) {
        if(dist == 0) return 0;
        else return 1e8;
    }
    if(dp_3d[dist][energy][idx] != -1) return dp_3d[dist][energy][idx];

    int time = 1e8;
    for(int i=0; i<=dist && i*arr[idx].e <= energy; i++){
        time = min(time, i*(arr[idx].m*60 + arr[idx].s) + minTimeReq(dist-i, energy-i*arr[idx].e, idx+1));
    }
    return dp_3d[dist][energy][idx] = time;
}
 
void solve(){
    int d, h;
    cin>>d>>h;
    arr.assign(5, Metric());
    for(int i=0; i<5; i++){
        int m, s, e;
        cin>>m>>s>>e;
        arr[i] = {m,s,e};
    }

    // dp.assign(d+1, vector<int>(h+1, -1));
    // int time = marathon(d, h);
    // cout<<time/60<<" "<<time%60<<'\n';
    
    dp_3d.assign(d+1, vector<vector<int>>(h+1, vector<int>(5, -1)));
    int time = minTimeReq(d, h, 0);
    cout<<time/60<<" "<<time%60<<'\n';
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<'\n';
    }
    return 0;
}