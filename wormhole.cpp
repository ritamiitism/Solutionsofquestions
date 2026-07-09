/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/

#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y,cost;
    Point(){};
    Point(int x,int y):x(x),y(y){};
    Point(int x,int y,int cost):x(x),y(y),cost(cost){};
    friend istream& operator>>(istream& s,Point& p){
        s>>p.x>>p.y;
        return s;
    }
    friend bool operator==(Point&s,Point& p){
        return s.x==p.x && s.y==p.y;
    }
};
int N = 1001;
int dist[1001][1001];
int main(){
    Point src,dest;
    cin>>src>>dest;
    int n;
    cin>>n;
    // vector<pair<Point,Point>> wormholes(n);
    // for(auto &i:wormholes){
    //     cin>>i.first>>i.second>>i.first.cost;
    // }
    struct Compare {
        bool operator()(const Point &a, const Point &b) const {
            return (a.x * 10000 + a.y) < (b.x * 10000 + b.y);
        }
    };
    map<Point,pair<int,Point>,Compare> mpp; //wormholes

    for(int i=0;i<n;i++){
        Point x,y;int cost;
        cin>>x>>y>>cost;
        int cost1 = cost,cost2=cost;
        if(mpp.find(x)!=mpp.end() && mpp[x].second==y){
            cost1 = min(cost, mpp[x].first);
        }
        if(mpp.find(y)!=mpp.end() && mpp[y].second==x){
            cost2 = min(cost, mpp[y].first);
        }
        mpp[x] = {cost1, y};
        mpp[y] = {cost2, x};
    }
    
    // [ a , b ->pq
    
    auto comp = [&](pair<Point,int>&a, pair<Point,int>&b){
        return a.second > b.second;
    };
    priority_queue<pair<Point,int>,vector<pair<Point,int>>, decltype(comp)>pq(comp);
    std::fill(dist[0],dist[0]+(N*N),(int)1e8);
    
    pq.push({src,0});
    dist[src.x][src.y] = 0;
    
    int dx[] = {0,-1,0,1};
    int dy[] = {-1,0,1,0};
    
    auto isValid = [&](int X,int Y){
        if(X<0 || X>=N || Y<0 ||Y>=N)return false;
        return true;
    };


    while(!pq.empty()){
        pair<Point,int> x = pq.top();
        pq.pop();

        if(x.first == dest){
            cout<<x.second<<endl;
            break;
        }

        if(x.second > dist[x.first.x][x.first.y])continue;

        for(int i=0;i<4;i++){
            int X = x.first.x + dx[i];
            int Y = x.first.y + dy[i];
            if(isValid(X,Y) && dist[X][Y]>x.second + 1){
                dist[X][Y] = x.second + 1;
                pq.push({Point(X,Y),x.second+1});
            }
        }

        if(mpp.find(x.first)!=mpp.end()){
            pair<int,Point> y = mpp[x.first];
            if(dist[y.second.x][y.second.y]>x.second + y.first){
                dist[y.second.x][y.second.y] = x.second + y.first;
                pq.push({y.second,x.second + y.first });
            }
        }  
    }

    return 0;
}
