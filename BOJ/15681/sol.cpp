#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int ans[100005];
int n,r,q;

void countSubtree(int cur, int parent){
    ans[cur]=1;
    for(int ch: adj[cur]){
        if(ch==parent)continue;
        countSubtree(ch,cur);
        ans[cur]+=ans[ch];
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>r>>q;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    countSubtree(r,-1);
    
    while(q--){
        int Q;cin>>Q;
        cout<<ans[Q]<<'\n';
    }
}
