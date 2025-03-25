#include<bits/stdc++.h>
using namespace std;

int go(int n, int m){
    vector<int> adj[501];
    bool vis[501]={false,};
    int p[501]={0,};
    int ret=0;

    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;

        queue<int> Q;
        bool istree=true;

        Q.push(i);
        vis[i]=true;
        p[i]=0; // 루트라는 의미
        while(!Q.empty()){
            int cur=Q.front();Q.pop();
            for(int nxt:adj[cur]){
                if(vis[nxt] and nxt==p[cur]) continue;
                if(vis[nxt] and nxt!=p[cur]){
                    istree=false;
                    continue;
                }
                Q.push(nxt);
                vis[nxt]=true;
                p[nxt]=cur;
            }
        }        
        if(istree)ret++;
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m, cnt=1;
    while(1){
        cin>>n>>m;
        if(n==0 and m==0)break;
        int cs =go(n,m);

        if(cs==0)cout<<"Case "<<cnt++ <<": No trees." <<'\n';
        else if(cs==1) cout<<"Case "<<cnt++ <<": There is one tree."<<'\n';
        else cout<<"Case "<<cnt++ <<": A forest of "<<cs <<" trees."<<'\n';
    }
}