#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second 

pair<int,int> arr[500005];
int n; 

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].X>>arr[i].Y;
    }
    sort(arr,arr+n,greater<pair<int,int>>());

    multiset<int> s; // 팀원 수를 저장, -(팀원 수)

    for(int i=0;i<n;i++){
        auto it = s.lower_bound(-arr[i].Y+1); // k가 2면, -1보다 크거나 같은 수를 반환 -> (-1)은 arr[i].X보다 큰 인원이 1명밖에 없는 팀
        // 자신이 들어갈 수 있는 최대 크기의 팀에 들어가야 그리디적으로 옳다. 그래서 음수로 바꾸는 테크닉이 통할 수 있다.
        if(it ==s.end()) s.insert(-1);
        else{
            int val = *it -1;
            s.erase(it);
            s.insert(val);
        }
    }
    cout<<s.size();
}