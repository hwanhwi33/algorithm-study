#include<bits/stdc++.h>
using namespace std;

vector<int> adj[32001];
vector<int> deg(32001);
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
    set<int> T;

    for(int i=1;i<=n;i++)
        if(deg[i]==0)T.insert(i);
    
    while(T.size()!=0){
        int cur=*T.begin();T.erase(*T.begin());
        cout<<cur<<' ';
        for(int nxt:adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0)T.insert(nxt);
        }
    }
}