#include<bits/stdc++.h>
using namespace std;

int board[31][11];
int n,m,h;


bool chk(){ //i-i 조건 만족하는지 확인하는 함수
    
    for(int j=1;j<=n;j++){
        int cur=j;
        for(int i=1;i<=h;i++){
            cur = cur+board[i][cur];
        }
        if(cur!=j) return 0;
    }
    return 1;
}

int solve(){
    if(chk()) return 0; // 가로선 추가 0인 경우

    int ans=4;
    for(int i1=1;i1<=h;i1++){ // i1: 첫번째 가로줄의 점선 위치
        for(int i2=1;i2<n;i2++){ // i2: 첫번째 가로줄의 세로선 위치
            if(board[i1][i2]!=0 or board[i1][i2+1]!=0) continue; //선이 겹쳐지는 경우
            board[i1][i2]=1;
            board[i1][i2+1]=-1;
            if(chk()) return 1;


            for( int j1=i1 ;j1<=h;j1++){ // j1: 두번째 가로줄의 점선 위치
                for( int j2=1 ;j2<n;j2++){ // j2: 두번째 가로줄의 세로선 위치
                    if(board[j1][j2]!=0 or board[j1][j2+1]!=0) continue; //선이 겹쳐지는 경우
                    board[j1][j2]=1;
                    board[j1][j2+1]=-1;
                    if(chk())ans= min(ans,2);



                    for(int k1=j1 ;k1<=h;k1++){ // k1: 세번째 가로줄의 점선 위치
                        for(int k2=1 ;k2<n;k2++){ // k2: 세번째 가로줄의 세로선 위치
                        if(board[k1][k2]!=0 or board[k1][k2+1]!=0) continue; //선이 겹쳐지는 경우
                        board[k1][k2]=1;
                        board[k1][k2+1]=-1;
                        if(chk())ans= min(ans,3);
                        board[k1][k2]=0;
                        board[k1][k2+1]=0;
                        }
                    }
                    board[j1][j2]=0;
                    board[j1][j2+1]=0;
                    
                }
            }
            board[i1][i2]=0;
            board[i1][i2+1]=0;
        }
    }
    if(ans!=4)return ans;
    else return -1;
    
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m>>h;
    while(m--){
        int a,b;
        cin>>a>>b;
        board[a][b]=1;
        board[a][b+1]=-1;
    }
    cout<< solve();


}

