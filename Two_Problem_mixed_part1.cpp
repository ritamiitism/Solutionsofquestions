/*
Given below are the raw materials quantities and their respective selling price(if sold as raw).
D --> No of CPUs       E --> No of memory chips      F --> No of boards
d --> Selling price of CPU     e --> Selling price of Memory chips

We are given N Computer configurations like below : 
Di, Ei, Fi, SPi, which are the CPU, Chips, Boards and one unit selling price for ith computer respectively.
Our task is to maximize the final cost.
Constraints:
1. Can use at Max 3 different Configurations
2. We can use 1 configuration multiple times
3. Remaining Inventories can be sold on its selling price

Input:
T --> Number of test cases.
D E F d e --> Inventories
N --> Total Configuration Count
Di Ei Fi SPi
...
Dn En Fn SPn

1<=T<=10
1<= D, E, F <= 100
1<= d, e <=100000
1<=N<=8

Output:
First Line print the Case #testCaseNumber
Second Line Print Maximum Cost per test case in each line.

Sample Input:
1 --> Total Test Case
10 10 10 2 1 --> D E F d e
1 --> PC Configuration Count
1 2 2 3 --> D1 E1 F1 SP1

Sample Output:
Case #1
30
*/

#include <bits/stdc++.h>
using namespace std;

int D, E, F, d, e;
struct config{
   int D, E, F, SP;
};

config comp[8];
int maxCost;

void recursion(int idx, int n, int cnt, int prev, int D, int E, int F, int cost){
    // Base case
    if(idx >= n){
        cost += (D*d + E*e);
        if(cost > maxCost) maxCost = cost;
        return;
    }
    
    // if cnt=3, but the last element can be taken multiple times 
    if(cnt == 3){
        if(prev == idx){
            // take the last one can be taken multiple times
            if(D >= comp[idx].D && E >= comp[idx].E && F >= comp[idx].F){
                recursion(idx, n, cnt, idx, D-comp[idx].D, E-comp[idx].E, F-comp[idx].F, cost+comp[idx].SP);
            }
            else{
                cost += (D*d + E*e);
                if(cost > maxCost) maxCost = cost;
                return;
            }
        }else{
            cost += (D*d + E*e);
            if(cost > maxCost) maxCost = cost;
            return;
        }
    }
    
    // skip that idx 
    recursion(idx+1, n, cnt, prev, D, E, F, cost);
    
    // taking that element 
    if(D >= comp[idx].D && E >= comp[idx].E && F >= comp[idx].F){
        if(prev == idx){   // taking that idx multiple times
        // no increase in no. of configurations
            recursion(idx, n, cnt, idx, D-comp[idx].D, E-comp[idx].E, F-comp[idx].F, cost+comp[idx].SP);
        }else{
            // taking that idx first time, increase in no. of configurations
            recursion(idx, n, cnt+1, idx, D-comp[idx].D, E-comp[idx].E, F-comp[idx].F, cost+comp[idx].SP);
        }
    }
    return;
}

void solve(){
    cin>>D>>E>>F>>d>>e;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>comp[i].D>>comp[i].E>>comp[i].F>>comp[i].SP;
    }
    
    maxCost = 0;
    
    recursion(0, n, 0, -1, D, E, F, 0);
    cout<<maxCost<<'\n';
    
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}