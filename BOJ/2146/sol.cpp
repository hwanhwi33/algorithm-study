#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int board[101][101];
int dist[101][101];
int num[101][101];
int n;

queue<pair<int,int>> load;

bool bfs(int cx, int cy, int cnt){
    queue<pair<int,int>> q;
    q.push({cx,cy});
    num[cx][cy]=cnt;

    while(!q.empty()){
        pair<int,int> cur=q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 or nx>=n or ny<0 or ny>=n)continue;
            if(num[nx][ny]==cnt)continue; // 이미 방문한 해당 섬의 육지거나, 인접한 바닷가
            
            if(board[nx][ny]==0){ // 방문 안한 인접한 바닷가
                if(num[nx][ny]!=0) return true; // 엣지케이스 (꼭짓점을 맞대고 섬이 존재하는 경우)
                num[nx][ny]=cnt;
                dist[nx][ny]=1;
                load.push({nx,ny});
            }
            else{ //board[nx][ny]==1
            q.push({nx,ny});
            num[nx][ny]=cnt;
            }
        }
    }
    return false;
}

int go(){
    
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1 and num[i][j]==0){
                bool isOne =bfs(i,j,cnt++);
                // cout<<cnt<<' ';
                if(isOne)return 1;
            }
        }
    }

    int mn=1000;
    while(!load.empty()){
        pair<int,int> cur=load.front();load.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 or nx>=n or ny<0 or ny>=n)continue;
            
            if(num[nx][ny]==num[cur.X][cur.Y])continue;
            if(num[nx][ny]!=0)mn=min(dist[nx][ny]+dist[cur.X][cur.Y],mn);
            else{
                num[nx][ny]=num[cur.X][cur.Y];
                dist[nx][ny]=dist[cur.X][cur.Y]+1;
                load.push({nx,ny});
            }
        }
    }
    return mn;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>board[i][j];
    
    cout<<go();
}