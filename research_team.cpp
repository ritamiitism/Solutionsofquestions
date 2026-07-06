/*
A Research team want to establish a research center in a region where they found some rare-elements.
They want to make it closest to all the rare-elements as close as possible so that they can reduce
overall cost of research over there. It is given that all the rare-element’s location is connected
by roads. It is also given that Research Center can only be build on road. Team decided to assign
this task to a coder. If you feel you have that much potential.

Here is the Task :- Find the shortest of the longest distance of research center from given locations
of rare-elements.

Locations are given in the matrix cell form where 1 represents roads and 0 no road. 
Number of rare-element and their location was also given(number<=5) and order of square matrix
was less than equal to (20).
*/

/*
For this you have to implement bfs for every position where road exist to find the distance of 
every research center or do Vice-versa. for each position store maximum distance of all distances
to research center and the compare each maximum distance to find minimum of them

To optimize this problem, we should run Breadth-First Search (BFS) starting 
from each rare-element instead of every single road cell.
Run BFS from each rare element location, and store the max_dist to reach to
that cell from all rare-elements, (store the fartest rare-element dist),
and then print the min of all grid values to get the grid location,
** Replace rare-elements with 3 to implement bfs in optimized way **
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> maxDist;
vector<vector<int>> reachCount; // Tracks how many rare elements reached each cell
vector<pair<int,int>> location;
vector<vector<bool>> vis;
int n, m;
vector<pair<int,int>> dirc = {{0,1}, {0,-1}, {1,0}, {-1,0}};

struct Node{
    int x, y, dist;
};
bool isValid(int x, int y){
    return (x>=0) && (y>=0) && (x<n) && (y<n);
}

// Highly optimized O( m * n * n)
void bfs(int idx){
    vis.assign(n, vector<bool>(n, false));
    int x = location[idx].first;
    int y = location[idx].second;
    
    queue<Node> q;
    q.push({x, y, 0});
    vis[x][y] = 1;
    reachCount[x][y]++;
    maxDist[x][y] = max(maxDist[x][y], 0);
    
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = curr.x + dirc[i].first;
            int ny = curr.y + dirc[i].second;
            if(isValid(nx, ny) && vis[nx][ny] == 0 && grid[nx][ny] == 1){
                q.push({nx, ny, curr.dist+1});
                vis[nx][ny] = 1;
                reachCount[nx][ny]++;
                
                maxDist[nx][ny] = max(maxDist[nx][ny], curr.dist+1);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    
    location.assign(m, {0,0});
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        location[i] = {x-1, y-1};
    }
    
    grid.assign(n, vector<int>(n, 0));
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    
    maxDist.assign(n, vector<int>(n, -1));
    reachCount.assign(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        bfs(i);
    }
    
    int minPossible = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1 && reachCount[i][j] == m){
                minPossible = min(minPossible, maxDist[i][j]);
            }
        }
    }
    cout<<((minPossible != INT_MAX) ? minPossible : -1)<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}