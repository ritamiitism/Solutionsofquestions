#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mii map<int,int>
#define vecin(vec) for(auto &i:(vec)) cin>>i;
#define print(vec) for(auto it = vec.begin(); it!=vec.end(); it++) cout<<*it<<' '; cout<<endl;
#define printpair(mp) for(auto it = mp.begin(); it!=mp.end(); it++) cout<<it->first<<' '<<it->second<<endl;
#define print2d(vec,r,c) for(int i=0;i<r;i++){for(int j=0;j<c;j++){cout<<vec[i][j]<<" \n"[j+1==c];}};
#define belongs(c,a,b) ((c)>=(a) && (c)<=(b))
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define pm cout<<"-1\n";
#define endl "\n"
#define pb push_back
#define mkp make_pair
#define int long long
vi dx={-1,1,0,0};
vi dy={0,0,-1,1};
/* -------------------------------------------------------x CODE STARTS HERE x------------------------------------------------------- */ 
struct pt{
    int x,y,d;
};

void saisriramdodda1302(){
    //research centre.
    vector<pt>rele;
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < k; i++)
    {   
        int u,v;
        cin>>u>>v;
        u--,v--;
        pt p;
        p.x=u;
        p.y=v;
        p.d=0;
        rele.pb(p);
    }
    vvi grid(n,vi(n));
    vector<vvi>dis(k,vvi(n,vi(n,-1e9)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>grid[i][j];
        }
    }
    
    for (int i = 0; i < k; i++)
    {   
        vvi vis(n,vi(n,0));
        queue<pt>q;
        q.push(rele[i]);
        dis[i][rele[i].x][rele[i].y]=0;
        while (!q.empty())
        {
            pt p=q.front();
            q.pop();    
            int x=p.x;
            int y=p.y;
            int ds=p.d;
            vis[x][y]=1;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx=x+dx[dir];
                int ny=y+dy[dir];
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]!=0 && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    dis[i][nx][ny]=ds+1;
                    pt np;
                    np.x=nx;
                    np.y=ny;
                    np.d=ds+1;
                    q.push(np);
                }
            }
            
        }
    }
    int ans=1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp=-1e9;
            for (int re = 0; re < k; re++)
            {
                temp=max(temp,dis[re][i][j]);   
            }
            if(temp==-1e9)
                continue;
            ans=min(ans,temp);
        }
    }
    cout<<ans<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t=1;
    cin>>t; 
    while(t--){
        saisriramdodda1302();
    }
    return 0;
}