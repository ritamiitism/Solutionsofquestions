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
vector<vector<vector<vector<int>>>> dp;
bool notValid(int i,int j, int n,int m)
{
    return !(i>=0 && i<=n && j<=m && j>=0);
}

int solve(int i,int j, int bomb, vector<vector<int>> &mat, int stepy,int n,int m)
{
    if(i<0)return 0;
    if(notValid(i,j,n,m))
    return INT_MIN;
    int step_state = min(stepy, 6);
    if(dp[i][j][bomb][step_state]!=-1)
    return dp[i][j][bomb][step_state];
    int bombed=0;
    if(bomb)
    {
        bombed=solve(i,j,0,mat,0,n,m);
        
    }
    int left=INT_MIN;
    int right=INT_MIN;
    int center=INT_MIN;
    if(mat[i][j]==2)
    {
        if(stepy<=4)
        {
            left=solve(i-1,j+1,bomb,mat,stepy+1,n,m);
            right=solve(i-1,j-1,bomb,mat,stepy+1,n,m);
            center=solve(i-1,j,bomb,mat,stepy+1,n,m);
        }
        else
        {
            return INT_MIN;
        }
    }
    else
    {
        int val=mat[i][j];
        left=val+solve(i-1,j+1,bomb,mat,stepy+1,n,m);
        right=val+solve(i-1,j-1,bomb,mat,stepy+1,n,m);
        center=val+solve(i-1,j,bomb,mat,stepy+1,n,m);
    }
    return dp[i][j][bomb][step_state]= max({bombed,left,right,center});
}

int main(){
    ll t;
    cin>>t;
    int test=0;
    while(t--){
        test++;
        int n,m;
        cin>>n;
        m=5;
        vector<vector<int>>mat(n+1,vector<int>(m+1,0));
        dp.assign(n+2,vector<vector<vector<int>>>(m+2,vector<vector<int>>(2,vector<int>(7,-1))));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        mat.push_back({0,0,0,0,0});
        cout<<"#"<<test<<" "<<solve(n,2,1,mat,6,n,m)<<endl;
        
        


    }
}
