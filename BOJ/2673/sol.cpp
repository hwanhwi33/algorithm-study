#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int board1[301][301]; // 현재 연도의 보드
int board2[301][301]; // 다음 연도의 보드 
int n,m;

bool vis[301][301];

void bfs(int cx,int cy){
    queue<pair<int,int>> q;
    q.push({cx,cy});
    vis[cx][cy]=true;

    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 or nx>=n or ny<0 or ny>=m)continue;
            if(board1[nx][ny]==0){
                if(board2[cur.X][cur.Y]>0) board2[cur.X][cur.Y]--; 
                continue;
            }
            if(vis[nx][ny])continue;

            q.push({nx,ny});
            vis[nx][ny]=true;
            
        }
    }
}

int go(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            board2[i][j]=board1[i][j]; 

    for(int i=0;i<n;i++)
        fill(vis[i],vis[i]+m,false);
    //초기화    
    
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(board1[i][j]==0)continue;
           if(vis[i][j])continue; // 빙산이 있지만, 방문한 경우

           bfs(i,j);
           cnt++;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            board1[i][j]=board2[i][j]; // 다음 연도로 업데이트 

    return cnt;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>board1[i][j];

    int cnt=1;
    int year=0;
    while(cnt==1){
        cnt=go();
        year++;
    }
    if(cnt==0)cout<<0;
    else cout<<year-1; // 시작 연도는 빼고 계산 
}
