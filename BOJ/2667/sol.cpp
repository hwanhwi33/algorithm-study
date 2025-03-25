#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

string board[26];
bool vis[26][26];
int n;

int bfs(int sx, int sy){
    queue<pair<int,int>> Q;
    Q.push({sx,sy});
    vis[sx][sy]=1;
    int cnt=1;

    while(!Q.empty()){
        auto cur = Q.front();Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 or nx>=n or ny<0 or ny>=n)continue;
            if(vis[nx][ny] or board[nx][ny]=='0')continue;
            Q.push({nx,ny});
            vis[nx][ny]=1;
            cnt++;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
            cin>>board[i];
    
    vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        if(vis[i][j] or board[i][j]=='0')continue;
        v.push_back(bfs(i,j));
        }
    }
    cout<<v.size()<<'\n';
    sort(v.begin(),v.end());
    for(int i:v)cout<<i<<'\n';
}
