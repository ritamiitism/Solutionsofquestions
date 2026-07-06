#include<bits/stdc++.h>

using namespace std;
void genNum(const vector<int>&num,int o,unordered_map<long long,int> &mp , string curr)
{
   if(!curr.empty())
   {
       long long val=stoll(curr);
       if (val > 100000) return;
       int touch=curr.length();
       if(mp.find(val)==mp.end() || touch<mp[val])
       {
           mp[val]=touch;
       }
     
   }
     if(curr.length()>=o)
       return;
       
       for(auto it:num)
       {
           if(curr=="0")
           continue;
           
           genNum(num,o,mp,curr+to_string(it));
       }
    
}

int main() {
    
    int n,m,o;
    cin>>n>>m>>o;
    vector<int>dials(n);
    vector<int>op(m);
    for(int i=0;i<n;i++)
    cin>>dials[i];
    for(int i=0;i<m;i++)
    cin>>op[i];
    
    long long tar;
    cin>>tar;
    
   priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    unordered_map<long long,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[dials[i]]=1;
    }
    genNum(dials,o,mp,"");
    if(mp.find(tar)!=mp.end())
    {
        cout<<mp[tar]<<endl;
        return 0;
    }
    unordered_map<long long,int>vis;
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
        vis[it.first]=it.second;
    }
    while(!pq.empty())
    {
        long long curr=pq.top().second;
        int steps=pq.top().first;
        pq.pop();
        if(steps>o)
        continue;
        if(curr==tar)
        {
            cout<<(steps+1)<<endl;
            return 0;
            
        }
        long long next;
        
        for(auto it:mp)
        {
            int next_steps = steps + 1 + it.second;
            
            // If touches + 1 (for the '=' sign) exceeds limit, skip it completely!
            if(next_steps + 1 > o) {
                continue;
            }
            for(int j=0;j<m;j++)
            {
                bool valid=false;
                if(op[j]==1)
                {
                    next=curr+it.first;
                   
                    valid=true;
                    
                }
                if(op[j]==2)
                {
                    next=curr-it.first;
                    valid=true;
                }
                if(op[j]==3)
                {
                    next=curr*it.first;
                    valid=true;
                }
                if(op[j]==4)
                {
                    if(it.first==0 || curr%it.first!=0)
                    {
                        valid=false;
                        continue;
                    }
                    next=curr/it.first;
                    valid=true;
                    
                }
                if(valid && (vis.find(next)==vis.end() || vis[next]>steps+1+it.second)){
                pq.push({steps+1+it.second,next});
                    vis[next]=steps+1+it.second;
                }
            }
        }
        
    }
    
	

}
