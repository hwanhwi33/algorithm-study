#include<bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int dist[51];
int n;
int score[51];

void bfs(int st){
    fill(dist+1,dist+n+1,-1);
    queue<int> q;
    q.push(st);
    dist[st]=0;

    while(!q.empty()){
        int cur=q.front();q.pop();
        for(int nxt:adj[cur]){
            if(dist[nxt]>=0)continue;
            q.push(nxt);
            dist[nxt]=dist[cur]+1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    while(1){
        int u,v;
        cin>>u>>v;
        if(u==-1 and v==-1)break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int mn=100; // 회장 후보 점수
    for(int i=1;i<=n;i++){
        bfs(i);
        int cs=0; // cur_sore
        for(int j=1;j<=n;j++){
            cs=max(cs,dist[j]);
        }
        mn=min(mn,cs);
        score[i]=cs;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(score[i]==mn)cnt++;
    }
    cout<<mn<<' '<<cnt<<'\n';
    for(int i=1;i<=n;i++){
        if(score[i]==mn)cout<<i<<' ';
    }

}