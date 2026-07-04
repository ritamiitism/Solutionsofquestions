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
        int n,e,ti;
        cin>>n>>e>>ti;
        ti=ti/10;
        vector<vector<pair<int,float>>>adj(n+1);
        for(int i=0;i<e;i++)
        {
            int a,b;
            float w;
            cin>>a>>b>>w;
            adj[a].push_back({b,w});
        }
        queue<pair<int,pair<int,float>>>q;
        q.push({1,{0,1}});
        vector<vector<float>>p(n+1,vector<float>(ti+5,0.0));
        while(!q.empty())
        {
            auto it=q.front();
            int currNode=it.first;
            int currTime=it.second.first;
            float currProb=it.second.second;
            q.pop();
            if(currTime>ti)
            continue;
            for(auto ch:adj[currNode])
            {
                int child=ch.first;
                float w=ch.second;
                p[child][currTime+1]+=w*currProb;
                q.push({child,{currTime+1,w*currProb}});

            }
        }
        float ma=0;
        for(int i=1;i<=n;i++)
        {
            ma=max(ma,p[i][ti]);
        }
        cout <<  fixed << setprecision(6) << ma << "\n";

    }
}
