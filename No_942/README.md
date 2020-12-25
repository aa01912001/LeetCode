題號: 942. DI String Match

難度: Easy

## 問題描述
Given a string `S` that **only** contains "I" (increase) or "D" (decrease), let `N = S.length`.

Return **any** permutation `A` of ``[0, 1, ..., N]`` such that for all `i = 0, ..., N-1`:

- If `S[i] == "I"`, then `A[i] < A[i+1]`
- If `S[i] == "D"`, then `A[i] > A[i+1]`

Example 1:
```
Input: "IDID"
Output: [0,4,1,3,2]
```
---
## 解決思路
對於I來說，可以從0開始累加，而對於D來說，則從N開始下降，如此就保證了在結束前兩者決不會相遇，到最後一個數字個時候兩者相同，再將這個數字加入即可。
