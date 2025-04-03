#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m; // 정점과 간선 개수
vector<pair<int,int>> adj[10001];
bool vis[10001];
int mst=0; // 최소신장트리의 가중치

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj[v].push_back({u,t});
    }
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    for(auto one:adj[1])pq.push({one.second,1,one.first});
    vis[1]=true;

    while(!pq.empty()){
        int t,x,y;
        tie(t,x,y)=pq.top();pq.pop();
        if(vis[y])continue;
        
        for(auto nxt:adj[y]){
            pq.push({nxt.second,y,nxt.first});
        }
        vis[y]=true;
        mst+=t;

    }
    cout<<mst;

}