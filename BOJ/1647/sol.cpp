#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

vector<pair<int,int>> adj[100001];
bool vis[100001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
int n,m;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    int cnt=0;
    int mst=0;
    int mx=0; // 끊을 간선 
    vis[1]=true;
    for(auto st:adj[1]){
        pq.push({st.first,st.second});
    }
    while(cnt<n-1){
        auto cur=pq.top();pq.pop();
        if(vis[cur.second])continue;
        vis[cur.second]=true;
        mst+=cur.first;
        mx=max(mx,cur.first);
        cnt++;
        for(auto nxt:adj[cur.second]){
            if(!vis[nxt.second])
            pq.push({nxt.first,nxt.second});
        }
    }
    cout<<mst-mx;
}   
