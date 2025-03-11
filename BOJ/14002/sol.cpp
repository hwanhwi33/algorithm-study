#include<bits/stdc++.h>
using namespace std;

int arr[1001];
int d[1001]; // i번째 수를 포함한 가장 큰 감소 수열 (i~n-1)
int nxt[1001]; // i번째 다음으로 큰 수의 인덱스 저장
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    d[n]=1;

    for(int i=n-1;i>0;i--){
        int mx=0,idx=0;
        for(int j=i;j<=n;j++){
            if(arr[i]<arr[j] and mx<d[j]){
                mx=d[j];
                idx=j;
            }
        }
        d[i]=mx+1;
        nxt[i]=idx;
    }
    cout<<*max_element(d+1,d+n+1)<<'\n';
    int idx=max_element(d+1,d+n+1)-d;
    
    while(1){
        cout<<arr[idx]<<' ';
        if(nxt[idx]==0)break;
        idx=nxt[idx];
    }
}