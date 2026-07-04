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
int k;
int dp[20][2][20];
int solve(string &s,int idx,int tight,unordered_set<int>&st,int cnt)
{
    if(cnt>=k)return 0;
    if(idx==s.size()) return 1;
    if(dp[idx][tight][cnt]!=-1) return dp[idx][tight][cnt];

    int limit=tight?(s[idx]-'0'):9;
    int ans=0;
    

    for(int i=0;i<=limit;i++)
    {
        int udt=0;
        if(st.find(i)!=st.end())
        {
           udt++;
        }   
        ans+=solve(s,idx+1,(tight&(i==s[idx]-'0')),st,cnt+udt);
    }
    return dp[idx][tight][cnt]=ans;
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r>>k;
        memset(dp,-1,sizeof(dp));

        unordered_set<int>st;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int d;
            cin>>d;
            st.insert(d);
        }
        string rs=to_string(r);
        int rightAns=solve(rs,0,1,st,0);
        string ls=to_string(l-1);
        memset(dp,-1,sizeof(dp));

        int leftAns=solve(ls,0,1,st,0);
        cout<<(rightAns-leftAns)<<" ";


    }
}
