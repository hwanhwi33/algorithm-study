#include<bits/stdc++.h>
using namespace std;

int d[2][100001];


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;cin>>T;

    while(T--){
        int n; cin>>n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>d[i][j];
            }
        }

        if(n==1)cout<<max(d[0][0],d[1][0])<<'\n';
        else{
            d[0][1]+= d[1][0];
            d[1][1]+= d[0][0];

            for(int j=2;j<n;j++){
                for(int i=0;i<2;i++){
                    d[i][j]=max(d[1-i][j-1],d[1-i][j-2])+d[i][j];
                }
            }
            cout<<max({d[0][n-1],d[0][n-2],d[1][n-1],d[1][n-2]})<<'\n';
        }

    }
}