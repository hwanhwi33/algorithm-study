#include<bits/stdc++.h>
using namespace std;

int arr[20001]; // -10000~10000; X+10000으로 접근
int n;
long long ans=0;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    vector<int> pu;
    vector<int> mi;
    int ze=0;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        if(num<0 and arr[10000+num]==0)mi.push_back(num);
        else if(num>0 and arr[10000+num]==0)pu.push_back(num);
        else if(num==0) ze++;
        arr[num+10000]++;
    }
    sort(mi.begin(),mi.end()); // 오름차순 
    sort(pu.begin(),pu.end(),greater<int>()); // 내림차순

    // m은 최소부터 p는 최대부터 탐색함.
    for(int m:mi){
        for(int p:pu){
            int x=-(m+p);
            if(arr[x+10000]==0)continue; // 존재유무 확인
            if(x<m or p<x)continue; // 중복 제거
            
            if(p!=x and m!=x){
                ans+=(long long)arr[p+10000]*arr[m+10000]*arr[x+10000];
            }
            else{
                if(arr[x+10000]<=1) continue;
                else if(p==x) ans+= (long long)arr[x+10000]*(arr[x+10000]-1)/2*arr[m+10000]; //arr[x']C2 *arr[m'];
                else ans+= (long long)arr[x+10000]*(arr[x+10000]-1)/2*arr[p+10000]; //arr[x']C2 *arr[p'];
            }

        }
    }
    if(ze>=3)ans+=(long long)ze*(ze-1)*(ze-2)/6; // zeC3

    cout<<ans;

}

//cout<< "m: " <<m <<" p: " <<p <<" x: " <<x<<'\n';