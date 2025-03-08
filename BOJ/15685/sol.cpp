#include<bits/stdc++.h>
using namespace std;

int dx[]={0,-1,0,1}; 
int dy[]={1,0,-1,0};
// 오른, 위, 왼, 아래
int board[101][101];
int n;
int ans=0;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    while(n--){
        vector<int> drag; // 한 드래곤 커브의 방향을 저장하는 배열
        int x,y,d,g;
        cin>>y>>x>>d>>g; // x: 가로 y:세로 로 바꿈.(실수를 줄이기 위해서)
        drag.push_back(d);

        board[x][y]=1; // 0세대 드래곤 커브 세팅
        board[x+dx[d]][y+dy[d]]=1;
        x+=dx[d];
        y+=dy[d];

        for(int i=1;i<=g;i++){ //세대 확장
            vector<int> tmp;
            for(int idx=drag.size()-1;idx>=0;idx--){ // i-1세대에서 i세대로 업데이트
                int nxt=(drag[idx]+1)%4; // 나아갈 다음 방향
                board[x+dx[nxt]][y+dy[nxt]]=1;
                x+=dx[nxt];
                y+=dy[nxt];
                tmp.push_back(nxt);
            }
            for(int x: tmp) drag.push_back(x); // drag 업데이트
        }
    }
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(board[i][j]==1 and board[i+1][j]==1 and board[i][j+1]==1 and board[i+1][j+1]==1) ans++; 
        }
    }
    cout<<ans;



}