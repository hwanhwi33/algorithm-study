#include<bits/stdc++.h>
using namespace std;

int Time[100001];
int n,k;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>k;

    fill(Time,Time+100001,-1);
    queue<int> q;
    Time[n]=0;
    q.push(n);

    while(!q.empty()){
        int cur=q.front();q.pop();
        if(cur==k) break;
        for(int dir=0;dir<3;dir++){
            int nx;
            if(dir==0) nx=cur*2;
            else if(dir==1) nx=cur-1;
            else nx =cur+1;

            if(nx<0 or nx>100000) continue; // 제외조건
            if(Time[nx]>=0) continue;
            
            if(dir==0) Time[nx]=Time[cur];  // 순간이동
            else Time[nx]=Time[cur]+1; // 걷기
            q.push(nx);
        }
    }
    cout<<Time[k];

}