#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int adj[1001][1001];
bool chk[1001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>adj[i][j];
    
    for(int j=2;j<=n;j++)
        pq.push({adj[1][j],j});
    chk[1]=true;
    int cnt=0;
    long long mst=0;
    
    while(cnt<n-1){
        auto cur=pq.top();pq.pop();
        if(chk[cur.second])continue;
        mst+=cur.first;
        chk[cur.second]=true;
        cnt++;
        for(int j=2;j<=n;j++)
            if(!chk[j]) pq.push({adj[cur.second][j],j});
    }
    cout<<mst;
    
}