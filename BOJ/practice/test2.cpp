#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> indegree(101);

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    for(int i=0;i<7;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> Q;
    for(int i=1;i<=7;i++){
        if(indegree[i]==0)
            Q.push(i);
    }
    while(!Q.empty()){
        int cur=Q.front();Q.pop();
        cout<<(char)(cur-1+'A');

        for(int nxt:adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt]==0)Q.push(nxt);
        }
    }
}