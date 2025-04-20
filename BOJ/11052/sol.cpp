#include<bits/stdc++.h>
using namespace std;

int p[1001];
int d[1001];
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i];
    d[1]=p[1];
    
    for(int i=2;i<=n;i++){
        int tmp=0;
        for(int j=i-1;j>0;j--){
            tmp=max(tmp, d[j]*(i/j)+d[i%j]);
        }
        d[i]=max(p[i], tmp);
    }
    cout<<d[n];

}