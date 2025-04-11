#include<bits/stdc++.h>
using namespace std;

int d[41];
bool vip[41];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;

    while(m--){
        int v;cin>>v;
        vip[v]=true;
    }
    if(vip[1] or vip[2]){
        d[1]=d[2]=1;
    }
    else{
        d[1]=1;
        d[2]=2;
    }

    for(int i=3;i<=n;i++){
        if(vip[i] or vip[i-1]){
            d[i]=d[i-1];
        }
        else{
            d[i]=d[i-1]+d[i-2];
        }
    }
    cout<<d[n];


}