#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int board[101][101]; // 판
bool vis[101][101];
vector<int> area; // 영역의 넓이
int cnt=0; // 영역의 개수
int n,m,k;

void bfs1(int sx, int sy, int ex,int ey){
    for(int i=0;i<m;i++)fill(vis[i], vis[i]+n,false);
    queue<pair<int,int>> Q;
    Q.push({sx,sy});
    board[sx][sy]=1;
    vis[sx][sy]=1;
    while(!Q.empty()){
        auto cur=Q.front();Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<ex or nx>sx or ny<sy or ny>ey)continue;
            if(vis[nx][ny])continue;
            Q.push({nx,ny});
            vis[nx][ny]=1;
            board[nx][ny]=1;
        }
    }
}

void bfs2(){
    for(int i=0;i<m;i++)fill(vis[i], vis[i]+n,false);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0 and !vis[i][j]){
                cnt++; // 영역 개수+=1
                queue<pair<int,int>> Q;
                Q.push({i,j});
                vis[i][j]=1;
                int tmp=1; // 넓이 계산하기 위한 임시 변수
                while(!Q.empty()){
                    auto cur=Q.front();Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx=cur.X+dx[dir];
                        int ny=cur.Y+dy[dir];
                        if(nx<0 or nx>=m or ny<0 or ny>=n)continue;
                        if(vis[nx][ny] or board[nx][ny]==1)continue;
                        Q.push({nx,ny});
                        vis[nx][ny]=1;
                        tmp++;
                    }
                }
                area.push_back(tmp);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>m>>n>>k; 
    while(k--){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    bfs1(m-y1-1,x1,m-y2,x2-1);    
}
    bfs2();
    sort(area.begin(),area.end());
    cout<<cnt<<'\n';
    for(int a:area)cout<<a<<' ';
    

}