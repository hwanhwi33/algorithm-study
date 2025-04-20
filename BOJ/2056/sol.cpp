#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
vector<int> reAdj[10001];
int Time[10001];
int indegree[10001];
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int T,m,u;
        cin>>T>>m;

        Time[i]=T;
        indegree[i]=m;

        while(m--){
            cin>>u;
            adj[u].push_back(i);
            reAdj[i].push_back(u);
        }
    } // 입력 

    queue<int> Q;
    for(int i=1;i<=n;i++)
        if(indegree[i]==0) Q.push(i);
        
    
    
    while(!Q.empty()){
        int cur=Q.front();Q.pop();
        for(int nxt: adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt]==0){
                int mx=0;
                for(int pre: reAdj[nxt]){
                    mx=max(mx,Time[pre]);
                }
                Time[nxt]+=mx;
                Q.push(nxt);
            }
        }
    }
    cout<<*max_element(Time+1,Time+n+1);

}