#include<bits/stdc++.h>
using namespace std;

int dp[1001][31];
int T, w;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>T>>w;
    int cur=0;
    for(int i=1;i<=T;i++){
        if(cur<w)cur++;

        for(int j=0;j<=cur;j++){
            if(j==0)dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
        }
        int tree;cin>>tree;
        for(int j=0;j<=cur;j++){
            if(tree==1 and j%2==0)dp[i][j]++;
            if(tree==2 and j%2==1)dp[i][j]++;
        }
    }   
    cout<<*max_element(dp[T],dp[T]+cur+1);
}