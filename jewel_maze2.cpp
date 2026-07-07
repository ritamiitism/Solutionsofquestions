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
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
 int n;

 int bestone=-1;
bool isValid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<n;
}
vector<vector<int>>vis;

vector<vector<int>>bestgrid;
int solve(vector<vector<int>>&grid,int gems,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        if(grid[i][j]==1)
        return INT_MIN;
        if(grid[i][j]==2)
        gems++;

        if(gems>bestone)
        {
            bestone=gems;
            bestgrid=grid;
            bestgrid[i][j]=3;
        }
        return gems;

        

    }
    int orig=grid[i][j];
    if(grid[i][j]==1)return  INT_MIN;
    if(grid[i][j]==2)gems++;
    int ans=INT_MIN;
    vis[i][j]=1;
    grid[i][j]=3;
    for(int it=0;it<4;it++)
    {
        int newi=i+dx[it];
        int newj=j+dy[it];
        if(isValid(newi,newj) && !vis[newi][newj])
        ans=max(ans,solve(grid,gems,newi,newj));


    }
    grid[i][j]=orig;
    if(grid[i][j]==2)gems--;
    vis[i][j]=0;
    return ans;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
       
        cin>>n;

        vector<vector<int>>grid(n,vector<int>(n,0));
        vis.assign(n,vector<int>(n,0));
        bestgrid.assign(n,vector<int>(n,0));
        bestone=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>grid[i][j];
        }
        solve(grid,0,0,0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << bestgrid[i][j] << " ";
            }
            cout << "\n";
        }
        
        // 2. Print the max jewels
        cout << bestone << "\n";






    }
}
