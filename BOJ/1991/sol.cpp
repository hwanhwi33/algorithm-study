#include<bits/stdc++.h>
using namespace std;

int n;
int lc[27];
int rc[27];

void pre(int cur){
    cout<<(char)('A'+cur-1);
    if(lc[cur])pre(lc[cur]);
    if(rc[cur])pre(rc[cur]);
}
void in(int cur){
    if(lc[cur])in(lc[cur]);
    cout<<(char)('A'+cur-1);
    if(rc[cur])in(rc[cur]);
}
void post(int cur){
    if(lc[cur])post(lc[cur]);
    if(rc[cur])post(rc[cur]);
    cout<<(char)('A'+cur-1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c,l,r;
        cin>>c>>l>>r;
        if(l!='.') lc[c-'A'+1]=l-'A'+1;
        if(r!='.') rc[c-'A'+1]=r-'A'+1;
    }
    pre(1);cout<<'\n';
    in(1);cout<<'\n';
    post(1);

}
