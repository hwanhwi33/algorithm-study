#include<bits/stdc++.h>
using namespace std;
int sushi[30001];
int Count[3001]; // 종류에 따른 개수
int n,d,k,c;
int mx=0;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>d>>k>>c;
    for(int i=1;i<=n;i++)cin>>sushi[i];

    int j;
    set<int> s;
    for(j=1;j<k;j++){
        Count[sushi[j]]++;
        s.insert(sushi[j]);
    }
    cout<<j<<' ';
    for(int i=1;i<=n;i++, j++){
        if(j>n)j-=n;
        Count[sushi[j]]++; // j 파트
        s.insert(sushi[j]);
        
        if(i>1){
        Count[sushi[i]]--;
        if(Count[sushi[i]]==0) s.erase(sushi[i]);
        }
        
        int cnt=0;
        if(s.find(c)==s.end()) cnt=s.size()+1;
        else cnt=s.size();
        mx=max(mx,cnt);
    }
    cout<<mx;
    if(!s.empty())cout<< *s.begin();

}