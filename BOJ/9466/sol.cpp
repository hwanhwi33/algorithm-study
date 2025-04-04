#include<bits/stdc++.h>
using namespace std;
int nxt[100001];
int isteam[100001];
bool vis[100001];
int n;

void No(int st, int en){
    int cur=st;
    while(cur!=en){
        isteam[cur]=1;
        cur=nxt[cur];
    }
}

void Yes(int st){
    isteam[st]=2;
    int cur=nxt[st];

    while(cur!=st){
        isteam[cur]=2;
        cur=nxt[cur];
    }
}

int go(){
    fill(isteam+1,isteam+n+1,0);
    fill(vis+1,vis+n+1,false);

    for(int i=1;i<=n;i++){
        if(isteam[i]==1 or isteam[i]==2)continue; // 이미 팀유무 확정된 인원
        
        int cur=i;
        vis[i]=true;  //사슬놀이 시작점

        while(1){
            cur=nxt[cur];
            if(isteam[cur]==1 or isteam[cur]==2){ // cur가 팀이 이미 있거나, 없을 때  그럼 현재 사슬은 팀이 없음.
                No(i,cur); break;
            }
            else{
                if(vis[cur]){ // 현재 사슬은 팀유무를 모르는 상태이나, 사이클이 발견됐을 때
                    No(i,cur);
                    Yes(cur);
                    break;
                }
                else{ // 사슬에 인원 추가
                    vis[cur]=true;
                }
            }
        }

    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(isteam[i]==1)cnt++; 
    
    return cnt; // 팀없는 인원 
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>nxt[i];
        cout<<go()<<'\n';
    }
}