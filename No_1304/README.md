題號: 1304. Find N Unique Integers Sum up to Zero

難度: Easy

## 問題描述

Given an integer `n`, return **any** array containing `n` **unique** integers such that they add up to `0`.

Example 1:

```
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
```

Constraints:

- `1 <= n <= 1000`



---
## 解決思路

此題只要將1、2、...、n-1還有他們的總和取負數返回即可。
