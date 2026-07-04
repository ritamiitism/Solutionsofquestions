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



int main(){
    ll t;
    cin>>t;
    while(t--){

        int n,m,k;
        cin>>n>>m>>k;

        vector<vector<int>>grid(n+1,vector<int>(m+1,0));

        for(int i=0;i<k;i++)
        {
            int a,b;
            cin>>a>>b;
            grid[a][b]=1;
        }

        vector<vector<int>>pref(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pref[i][j]=grid[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }

        int low=1;
        int hi=min(n,m);

        while(low<=hi)
        {
            int mid=low+(hi-low)/2;
            int flag=0;
            for(int i=1;i+mid-1<=n;i++)
            {
                for(int j=1;j+mid-1<=m;j++)
                {
                    int cnt=pref[i+mid-1][j+mid-1]-pref[i-1][j+mid-1]-pref[i+mid-1][j-1]+pref[i-1][j-1];
                    if(cnt<=1)
                    flag=1;
                }
            }
            if(flag)
            low=mid+1;
            else
            hi=mid-1;

        }
        cout<<low-1<<endl;



    }
}
