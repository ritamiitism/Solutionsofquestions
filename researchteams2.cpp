int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int n;
bool isValid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<n;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        int k;
        cin>>n>>k;

        vector<pair<int,int>>rare(k);

        for(int i=0;i<k;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            rare[i].first=x;
            rare[i].second=y;
        }
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cin>>grid[i][j];
        }
        vector<vector<int>>cost(n,vector<int>(n,0));
    

        for(int i=0;i<k;i++)
        {
            vector<vector<int>>vis(n,vector<int>(n,0));
            queue<pair<int,pair<int,int>>>q;
            q.push({0,{rare[i].first,rare[i].second}});
            vis[rare[i].first][rare[i].second]=1;
            
            vector<vector<int>>dis(n,vector<int>(n,1e9));
            dis[rare[i].first][rare[i].second]=0;
            while(!q.empty())
            {
                auto it=q.front();
                int cst=it.first;
                int x=it.second.first;
                int y=it.second.second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int chx=x+dx[i];
                    int chy=y+dy[i];
                    if(isValid(chx, chy) && grid[chx][chy] == 1 && !vis[chx][chy])
                    {
                        vis[chx][chy]=1;
                        if(dis[chx][chy]>cst+1)
                        {
                            dis[chx][chy]=cst+1;
                            q.push({cst+1,{chx,chy}});
                        }
                        cost[chx][chy]=max(cost[chx][chy],dis[chx][chy]);
                    }
                }
                

            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=min(ans,cost[i][j]);
                }
            }
        }
        cout<<ans<<endl;

    }
}
