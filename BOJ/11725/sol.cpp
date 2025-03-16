#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];
int n;

void dfs(int cur){
    for(int nxt:adj[cur]){
        if(nxt==p[cur]) continue; // 부모면 dfs 패스
        p[nxt]=cur;
        dfs(nxt);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for(int i=2;i<=n;i++)cout<<p[i]<<'\n';
}
