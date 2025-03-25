#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int> s_i; // string -> int
vector<string> i_s(1001); // int -> string 
// 입력값 처리

vector<int> adj[1001]; //입력받은 그래프
vector<int> indegree(1001);
//P-C 관계 찾기

vector<string> tree[1001]; // 부모-자식 관계 트리, 정답 출력할 것
vector<string> root; // 정답 출력용
// 출력 파트

int n,m;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){ 
        string s;
        cin>>s;
        s_i[s]=i;
        i_s[i]=s;
    }  
    cin>>m;
    while(m--){
        string s1,s2;
        cin>>s1>>s2;
        adj[s_i[s2]].push_back(s_i[s1]);
        indegree[s_i[s1]]++;
    }
    // 입력 처리

    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            Q.push(i);
            root.push_back(i_s[i]);
        }
    }

    while(!Q.empty()){
        int cur=Q.front();Q.pop();
        for(int nxt: adj[cur]){
            indegree[nxt]--;
            if(indegree[nxt]==0){
                Q.push(nxt);
                tree[cur].push_back(i_s[nxt]);
            }
        }
    }
    // P-C 관계 찾기

    vector<string> tmp;
    for(int i=1;i<=n;i++) tmp.push_back(i_s[i]);
    
    cout<<root.size()<<'\n';
    
    sort(root.begin(),root.end());
    for(string s: root)cout<<s<<' ';
    cout<<'\n';

    sort(tmp.begin(),tmp.end());
    for(string s: tmp){
        cout<<s<<' ' <<tree[s_i[s]].size();
        sort(tree[s_i[s]].begin(),tree[s_i[s]].end());
        for(string ch: tree[s_i[s]]){
            cout<<' '<<ch;
        }
        cout<<'\n';

    }
    //출력 처리(사전 순으로)

}