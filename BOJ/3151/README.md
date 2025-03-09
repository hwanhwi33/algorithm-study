# BOJ 3151 - 합이 0

## 알고리즘 태그
- 시뮬레이션(빡구현)

## 문제 링크
https://www.acmicpc.net/problem/3151


## 풀이 아이디어
직관풀이가 O(N^3)라 시간복잡도를 낮춰야겠다고 판단함.  
숫자 범위가 작아서, 2개를 고르고 1개를 인덱스 확인으로 O(N^2) 풀이를 적용함. 
음수와 양수를 나눠, N이 5000을 넘지 않도록 해서, 이상한 풀이가 나왔는데  

바킹독의 풀이를 보니까.  
와... 아니.. 시간이 넉넉하니까(4초). 10000에서 O(n^2)를 써도 됨...  (핵심포인트)  
그리고 개짧음... 너무 돌아가서 풀었다...   

바킹독 풀이  
// Authored by : SciEm
// Co-authored by : -
// http://boj.kr/b830d64c3ecd434ba3e554cc709dba3e
#include <bits/stdc++.h>
using namespace std;

int n;
int a[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);

  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      auto ub = upper_bound(a + j + 1, a + n, -a[i] - a[j]);
      auto lb = lower_bound(a + j + 1, a + n, -a[i] - a[j]);
      ans += ub - lb;
    }
  }
  cout << ans;
}
/*
두 명을 선택하고 나머지 한 명을 이분탐색으로 찾되 여러 개 있는 경우를
고려하여 upper_bound와 lower_bound를 이용한다.

