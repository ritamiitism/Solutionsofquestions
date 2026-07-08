/*
There are N pots. Every pots have some water in it. They may be partially filled. So there is a Overflow
Number 0 associated with every pot which tell how many minimum stone pieces are require for that pot
to overflow. So if for a pot 0-value is 5 it means minimum 5 stone pieces should be put in that pot to
make it overflow. Initially a crow watched those pots and by seeing the water level he anticipated 0-
value correctly for every pot (that is he knew 01 to On).
But when he came back in evening he found that every pot is painted from outside and he is not able to
know which pot has what 0-value. Crow wants some K pots to overflow. He wants to use minimum number of 
stones required to overflow K pots.
But only he knows the 0-value of pots he doesn't know now which pot has what 0-value. So the task is
that in what minimum number of stones he can make K pots overflow in worst case.
Input Format:
You will be given a function which contains an integer array 0 corresponding to 0-value of N pots {01, 02,
On) and a K - Value representing the number of pots which the crow wants to overflow
Output Format:
You need to return the Minimum number of stones (in the form of integer) required to make K pots
overflow in worst case.
If input is invalid, return -1.
Sample Test Case 1
Sample Input: {5,58}, 1
Sample Output: 10
Explanation:
Let say there are two pots
pot 1 has 0 value of 5, 01= 5
pot 2 has 0 value of 58, 02= 58
Let say crow wants to make one of the pot to overflow. If he knows which pot has what 0-value, he
would simple search for 5 stones and put them in pot 1 to make it overflow. But in real case he doesn't
know which pot has what 0-value so just 5 stones may not always work.
However, he does know that one pot has 0-value 5 and other has 58. So even in worst case he can make
one of the pot overflow just by using 10 stones. He would put 5 stones in one pot if it doesn't overflow
he would try the remaining 5 in the other pot which would definitely overflow because one of the pot
has 0-value of 5.
So the answer for above question is minimum 10 stones even in worst case.
Sample Test Case 2
Sample Input: {65,69}, 1
Sample Output: 69
Explanation:
Let say there are two pots
pot 1 has 0 value of 65, 01= 65
pot 2 has 0 value of 69, 02= 69
In worst case, crow will approach the pot with 69 O value first. After putting in 65 stones, the pot does
not overflow. Now if pot is changed, 65 more stones would be required, whereas if just 4 more stones
are put into same pot, it will overflow.
So the answer in this case is 69.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i,int k,vector<int>&arr){
    int n = arr.size();
    if(k==0)return 0;
    if(i==n-1){
        if(k==1)return arr[i]-arr[i-1];
        return 1e6;
    }
    
    int curr = (arr[i]-(i>0?arr[i-1]:0));
    int ans = (n-1-i)*curr+min(curr+f(i+1,k-1,arr),f(i+1,k,arr));
    return ans; 
}
/*
    3 7 15 22
      3  3  3  -> 3+
      4 12 19
        4  4
        8
*/

void solve(){
    int n, k;
    cin>>n>>k;
    
    // n=3, k=2, 5 8 10  -> output = 18
    // arr[i-1] + min(f(i-2, k), arr[i]-arr[i-1]+f(i-2, k-1))
    //     8     + min(  f(1,2) , arr[2]-arr[1] + f(1,1) )
    //     8     + min{    13   ,   10 - 8 + ( 5 + min{ f(0,1), 8-5+f(0,0)} )}
    //     8     + min{    13   ,      2   + ( 5 + min{    5,    3 + 0    } )}   -> 18
    
    vector<int> StonesReq(n);
    for(int i=0;i<n; i++){
        cin>>StonesReq[i];
    }
    sort(StonesReq.begin(), StonesReq.end());
    
    dp.assign(n, vector<int>(k+1, -1));
    cout<<f(0,k,StonesReq)<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}