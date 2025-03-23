#include<bits/stdc++.h>
using namespace std;

priority_queue<int> A;
priority_queue<int, vector<int>, greater<int>> B;
int mid;
int n;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);


    cin>>n>>mid; // 2번째 수는 무조건 출력이니까.
    A.push(mid);
    cout<<mid<<'\n'; // 초기 세팅
    
    for(int i=0;i<n-1;i++){
        int num; cin>>num;
        
        if(num<mid) A.push(num);
        else B.push(num);

        if(A.size()==B.size()+2){
           B.push(A.top());
           A.pop();
        }
        else if(A.size()+2==B.size()){
           A.push(B.top());
           B.pop();
        }
        else if(A.size()+1==B.size()){
           A.push(B.top());
           B.pop();
        }
        mid=A.top();
        cout<<mid<<'\n';
    }

}