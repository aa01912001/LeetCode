題號: 997. Find the Town Judge

難度: Easy

## 問題描述
In a town, there are `N` people labelled from `1` to `N`.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

1. The town judge trusts nobody.
2. Everybody (except for the town judge) trusts the town judge.
3. There is exactly one person that satisfies properties 1 and 2.

You are given `trust`, an array of pairs `trust[i] = [a, b]` representing that the person labelled `a` trusts the person labelled `b`.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return `-1`.

Example 1:
```
Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
```
Constraints:


- `1 <= N <= 1000`
- `0 <= trust.length <= 10^4`
- `trust[i].length == 2`
- `trust[i]` are all different
- `trust[i][0] != trust[i][1]`
- `1 <= trust[i][0], trust[i][1] <= N`


---
## 解決思路
此題首先必需要先從1~N找到哪個編號是法官，而尋找的方式就是判斷out-degree等於0(因為法官不相信任何人)，若發現每個人的out-degree皆大於0則返回-1。之後接著判斷是否除了法官以外的每個人是否都信任法官即可。