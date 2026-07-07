#include <bits/stdc++.h>

using namespace std;
int gate_pos[3];
int gate_num[3];

int solve(vector<int>permutation,int it,vector<int>&cur){
    if(it>=3) return 0;
    vector<int>pos;
    int steps = 0;
    int l = gate_pos[permutation[it]];
    int r = gate_pos[permutation[it]];
    for(int i=0;i<gate_num[permutation[it]];i++){
        while(l>=0 && cur[l] == 1) l--;
        while(r<cur.size() && cur[r] == 1) r++;

        int distL = 1e9, distR = 1e9;
        if(l>=0) distL = gate_pos[permutation[it]] - l + 1;
        if(r<cur.size()) distR = r - gate_pos[permutation[it]] + 1;

        if(distL == distR && i == gate_num[permutation[it]] - 1){
            cur[l] = 1;
            int next1 = solve(permutation,it+1,cur);
            cur[l] = 0;
            cur[r] = 1;
            int next2 = solve(permutation,it+1,cur);
            cur[r] = 0;
            for(int p:pos) cur[p] = 0;
            return min(next1,next2) + steps + distL;
        }
        else if(distL > distR){
            pos.push_back(r);
            cur[r] = 1;
            steps+= distR;
        }else{
            pos.push_back(l);
            cur[l] = 1;
            steps+= distL;
        }
    }
    int next = solve(permutation,it+1,cur);
    for(int i:pos) cur[i] = 0;
    return next + steps;
}

int main(){
    int spots;
    cin>>spots;
    for(int i=0;i<3;i++){
        cin>>gate_pos[i]>>gate_num[i];
        gate_pos[i]--;
    }

    vector<int>cur(spots,0);
    vector<int>ans;
    ans.push_back(solve({0,1,2},0,cur));
    ans.push_back(solve({0,2,1},0,cur));
    ans.push_back(solve({1,0,2},0,cur));
    ans.push_back(solve({1,2,0},0,cur));
    ans.push_back(solve({2,0,1},0,cur));
    ans.push_back(solve({2,1,0},0,cur));
    cout<<*min_element(ans.begin(),ans.end())<<endl;


}
