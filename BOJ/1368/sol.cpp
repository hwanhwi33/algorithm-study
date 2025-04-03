#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int adj[301][301];
bool chk[301];
int w[301]; // 우물 팔 때 드는 비용
int mn=0x7fffffff;
int n;


int mst(int st){
    int cost=0; // 현재 비용
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    fill(chk+1,chk+n+1,false);
    chk[st]=true;
    cost+=w[st];
    for(int i=1;i<=n;i++){
        if(i==st)continue;
        pq.push({adj[st][i],i});
        pq.push({w[i],i});
    }
    int cnt=1;
    while(cnt<n){
        auto cur=pq.top();pq.pop();
        if(chk[cur.second])continue;
        chk[cur.second]=true;
        cnt++;
        cost+=cur.first;

        for(int i=1;i<=n;i++){
            if(chk[i])continue;
            pq.push({adj[cur.second][i],i});
        }
    }
    return cost;

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>adj[i][j];
    }//인접행렬 입력

    for(int i=1;i<=n;i++){
        mn= min(mst(i),mn);
    }
    cout<<mn;
    


}