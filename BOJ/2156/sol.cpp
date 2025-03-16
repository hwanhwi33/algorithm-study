#include<bits/stdc++.h>
using namespace std;

int ac[10001];
int d[10001][2];
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ac[i];

    d[1][0]=ac[1];
    d[1][1]=ac[1];
    d[2][0]=d[1][1]+ac[2];
    d[2][1]=ac[2];

    for(int i=3;i<=n;i++){
        d[i][0]=d[i-1][1]+ac[i];
        d[i][1]=max({d[i-2][0],d[i-2][1],d[i-3][0],d[i-3][1]})+ac[i];
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=max({d[i][0],d[i][1],mx});
    }
    cout<<mx;

}