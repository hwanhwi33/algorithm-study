#include<bits/stdc++.h>
using namespace std;

vector<int> adj[40000];
int deg[40000];
int n,m;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0) Q.push(i);
    }
    while(!Q.empty()){
        int cur=Q.front();Q.pop();
        cout<<cur<<' ';
        for(int nxt:adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0)Q.push(nxt);
        }
    }


}