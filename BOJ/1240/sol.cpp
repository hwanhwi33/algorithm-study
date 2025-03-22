#include<bits/stdc++.h>
using namespace std;

int adj[1001][1001];
int d[1001]; // st로부터의 거리
int n,m;

int bfs(int st, int en){
    fill(d+1,d+n+1,0);
    queue<int> Q;
    Q.push(st);
    d[st]=0;

    while(!Q.empty()){
        int cur= Q.front();Q.pop();
        for(int nxt=1;nxt<=n;nxt++){
            int dist=adj[cur][nxt];
            if(dist==0)continue; // 연결X
            if(d[nxt]!=0)continue; // 부모 노드면 패스
            Q.push(nxt);
            d[nxt]=d[cur]+dist;
            if(nxt==en)return d[nxt];            
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v,d;
        cin>>u>>v>>d;
        adj[u][v]=d;
        adj[v][u]=d;

    }
    while(m--){
        int a,b;
        cin>>a>>b;
        cout<<bfs(a,b)<<'\n';
    }
}