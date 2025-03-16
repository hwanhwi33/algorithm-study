#include<bits/stdc++.h>
using namespace std;

int order[51][10];
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=9;j++)
            cin>>order[i][j];
    }
    int ans=0;
    vector<int> np;
    for(int i=2;i<=9;i++)np.push_back(i);

    do{
        int Torder[10]={}; // 8! 중에 어느 하나의 순서
        for(int i=1,idx=0;i<=9;i++){
            if(i==4)Torder[i]=1;
            else Torder[i]=np[idx++];
        }
        int Tans=0; // T에 대한 결과
        int cur= 1; // 이제 칠 사람 인덱스
        for(int i=1;i<=n;i++){ // i번째 이닝
            int run[4]={};// 주자 위치
            int out=0;
            while(out<3){
               if(cur==10)cur=1; // 계속 반복
               
                if(order[i][Torder[cur]]){ // 1,2,3,4타
                    run[0]=1;
                    for(int r=3;r>=0;r--){
                        if(run[r]==1){
                            if(r+order[i][Torder[cur]]>3) Tans++; // 홈베이스 들어온 경우
                            else run[r+order[i][Torder[cur]]]=1; 
                            run[r]=0;
                        }
                    }
                } 
                else //order[i][Torder[cur]]==0
                    out++;
               
               cur++;
            }


        }
        ans=max(Tans,ans);

    }while(next_permutation(np.begin(),np.end()));
    cout<<ans;
}