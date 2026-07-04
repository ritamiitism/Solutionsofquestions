#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define scd second
#define foi(i,n) for(ll i=0;i<n;i++) 


void bfs(vector<vector<ll>>&graph,ll s){
 queue<ll>q;
 vector<bool>visited(graph.size(),false);
 q.push(s);
 visited[s]=true;
 while(!q.empty()){
  ll node=q.front();
  q.pop();
  for(ll neighbor:graph[node]){
   if(!visited[neighbor]){
    visited[neighbor]=true;
    q.push(neighbor);
   }
  }
 }
}

ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b;
}

bool compareBySecond(pair<ll,ll> a,pair<ll,ll> b){
    return a.scd<b.scd;
}

ll binarySearchEqualOrLess(vector<ll>& arr,ll target){
    ll low=0,high=arr.size()-1,result=-1;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(arr[mid]<=target){
            result=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return result;
}

ll binarySearch(const vector<ll>& arr,ll target){
    ll left=0,right=arr.size()-1;
    while(left<=right){
        ll mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;
        else if(arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

string ask(ll n){
    cout<<n<<endl;
    string s;
    cin>>s;
    return s;
}

ll nextPowerOfTwo(unsigned ll n){
    if(n==0) return 1;
    if((n&(n-1))==0) return n;
    n|=(n>>1);
    n|=(n>>2);
    n|=(n>>4);
    n|=(n>>8);
    n|=(n>>16);
    n|=(n>>32);
    return n+1;
}

int solve(int mask,int curr,  vector<vector<int>>&dp,vector<vector<int>>&cost,int n)
{
    if(mask==(1<<n)-1)
    return cost[curr][n+1];

    if(dp[curr][mask]!=-1)
    return dp[curr][mask];

    int ans=INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(!(1<<i & mask))
        {
            ans=min(ans,cost[curr][i+1]+solve(mask | (1<<i),i+1,dp,cost,n));
        }
    }
    return dp[curr][mask]=ans;

}

int main(){
    ll t;
    cin>>t;
    int cnt=1;
    while(t--){

        int n;
        vector<pair<int,int>>pos;

        cin>>n;
        int xh,yh,xo,yo;
        cin>>xh>>yh>>xo>>yo;
        pos.push_back({xh,yh});
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;

            pos.push_back({x,y});
        }
        
        
        pos.push_back({xo,yo});
        vector<vector<int>>cost(n+2,vector<int>(n+2));
        for(int i=0;i<n+2;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                cost[i][j]=abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second);
            }
        }
        vector<vector<int>>dp(n+2,vector<int>(1<<n,-1));

        cout<<"#"<<cnt<<" "<<solve(0,0,dp,cost,n)<<endl;
        cnt++;
        





       


    }
}
