#include<bits/stdc++.h>
using namespace std;

int adj[101][101];
bool vis[101];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    for(int i=0;i<7;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
    }
    while(1){
        bool end=true;
        for(int j=1;j<=7;j++){ //나를 찍고 있는 정점이 있느지 확인
            bool isnow=true;
            for(int i=1;i<=7;i++){
                if(adj[i][j]==1){
                    isnow=false;
                    break;
                }
            }
            if(isnow and !vis[j]){
                cout<<j;
                vis[j]=1;
                for(int nxt=1;nxt<=7;nxt++){
                    if(adj[j][nxt]==1)adj[j][nxt]=0;
                }
                end=false;
            }
        }
        if(end)break;
    }

}