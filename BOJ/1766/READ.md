# BOJ `1766

## 알고리즘 태그
- 위상정렬  
- 우선순위 큐  

## 문제 링크
https://www.acmicpc.net/problem/1766



## 풀이 아이디어
-위상정렬에서 queue 대신 최솟값을 뽑아내면 됨.  
- 우선순위를 쓰면 된다.  
- 나는 vector<int>로 받아서, 매 순간 sort를 해야 된다는 풀이가 떠올랐다.  
- 하지만 시간복잡도가 O(V*VlgV + E)라 접고, tree를 이용해서 O(v*lgV+E)로 낮춰야겠다는 생각을 했다.  
- 하지만 set의 begin()만 쓰기 때문에, 우선순위 큐(priority_queue)를 쓰면 더 간단해진다. 