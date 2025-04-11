#include<bits/stdc++.h>
using namespace std;

int d[1000001];


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;cin>>T;

    d[1]=1;
    d[2]=2;
    d[3]=4;

    int MAX=1000000;
    int div=1000000009;
    for(int i=4;i<=MAX;i++){
        d[i]=(d[i-1]+d[i-2])%div;
        d[i]=(d[i]+d[i-3])%div;
    }

    while(T--){
        int n;
        cin>>n;
        cout<<d[n]<<'\n';
    }


}