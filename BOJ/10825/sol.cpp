#include<bits/stdc++.h>
using namespace std;

tuple<string, int ,int ,int> arr[100001];
int n;

bool cmp(const tuple<string,int,int,int>& a, const tuple<string,int,int,int>& b){
    string as,bs; // 증가
    int a1,a2,a3; // 내림, 오름, 내림
    int b1,b2,b3;
    tie(as,a1,a2,a3)=a;
    tie(bs,b1,b2,b3)=b;

    if(a1!=b1)return a1>b1;
    if(a2!=b2)return a2<b2;
    if(a3!=b3)return a3>b3;
    return as<bs;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int a,b,c; // a:국어, b: 영어, c: 수학
        cin>>name >>a>>b>>c;
        arr[i]={name,a,b,c};
    }
    sort(arr,arr+n,cmp); 
    for(int i=0;i<n;i++)
        cout<<get<0>(arr[i])<<'\n';  
}