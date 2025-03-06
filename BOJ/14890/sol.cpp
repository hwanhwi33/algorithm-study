#include<bits/stdc++.h>
using namespace std;
int MAP[101][101];
int n,L;
int ans=0;

int isUse(vector<int>& road){

    vector<int> vis(n,0);
    for(int i=1;i<n;i++){
        if(road[i]==road[i-1])continue;
        else if(road[i]>road[i-1]){
            if(abs(road[i]-road[i-1])>1) return 0; // 차이가 1보다 크면 탈락
            if(i-L<0) return 0; // 낮은 칸이 L만큼 반복되지 않음. (칸이 짧을 때)
            int ex=road[i-1];
            for(int j=i-1;j>=i-L;j--){
                if(road[j]!=ex)return 0; // 낮은 칸이 L만큼 반복되지 않음. (연속되지 않을 때)
                if(vis[j]==1)return 0; // 낮은 칸이 L만큼 반복되지 않음. (겹치는 경우)
                vis[j]=1;
            }
        }
        else{ //road[i]<road[i-1]
            if(abs(road[i]-road[i-1])>1) return 0; // 차이가 1보다 크면 탈락
            if(i+L>n) return 0; // 낮은 칸이 L만큼 반복되지 않음. (칸이 짧을 때)
            int ex=road[i];
            for(int j=i;j<i+L;j++){
                if(road[j]!=ex)return 0; // 낮은 칸이 L만큼 반복되지 않음. (연속되지 않을 때)
                if(vis[j]==1)return 0; // 낮은 칸이 L만큼 반복되지 않음. (겹치는 경우)
                vis[j]=1;
            }
        }
    }
    return 1;

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>L;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>MAP[i][j];
    
    for(int i=0;i<n;i++){
        vector<int> road1(n);
        vector<int> road2(n);
        for(int j=0;j<n;j++){
            road1[j]=MAP[i][j]; // 가로줄
            road2[j]=MAP[j][i]; // 세로줄
        }
        ans+=isUse(road1);
        ans+=isUse(road2);

        // if(isUse(road1)) cout<<"road1: "<< i <<'\n';
        // if(isUse(road2)) cout<<"road2: "<< i <<'\n';
    }
    cout<<ans;
}