#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
    Point(){};
    Point(int a,int b):x(a),y(b){};
    friend istream& operator>>(istream& stream,Point&p){
        stream>>p.x>>p.y;
        return stream;
    };
    friend ostream& operator<<(ostream& stream,Point&p){
        stream<<p.x<<" "<<p.y;
        return stream;
    };
};

int n;
vector<Point> points;
vector<Point> lower;
vector<Point> upper;

void print(){
    for(auto &p:lower){
        cout<<p<<endl;;
    }
    for(auto &p:upper){
        cout<<p<<endl;;
    }
}

/*
    Andrew's Monotone Chain - nlogn
*/

// 1 means positive
int getDirection(Point a,Point b){
    // a*b = |a||b| sintetha
    /*
        axb =  [i , j ,k]
              [a.x a.y 0]
              [b.x b.y 0]
            = (a.x b.y - a.y-b.x);
    */
   return ((a.x*b.y) - (a.y*b.x));
}
void getConvexHull(){

    auto comp =[&](Point&p1,Point&p2){
          if (p1.x == p2.x) return p1.y < p2.y;
          return p1.x < p2.x;
    };
    sort(points.begin(), points.end(), comp);
    
    int s = lower.size();
    for(int i=0;i<n;i++){
        while(s>=2 && getDirection(Point(lower[s-1].x-lower[s-2].x, lower[s-1].y-lower[s-2].y), Point(points[i].x-lower[s-1].x, points[i].y-lower[s-1].y))<=0){
            lower.pop_back();
            s--;
        }
        lower.push_back(points[i]);
        s++;
    }


    lower.pop_back();

    
    s = upper.size();
    for(int i=n-1;i>=0;i--){
        while(upper.size()>=2 && getDirection(Point(upper[s-1].x-upper[s-2].x, upper[s-1].y-upper[s-2].y), Point(points[i].x-upper[s-1].x, points[i].y-upper[s-1].y))<=0){
            upper.pop_back();
            s--;
        }
        upper.push_back(points[i]);
        s++;
    }
    upper.pop_back();
    print();
}

int main(){
    cin>>n;
    points.assign(n,Point(0b0,0b0));


    for(int i=0;i<n;i++){
        cin>>points[i];
    }

    getConvexHull();
    return 0;
}
