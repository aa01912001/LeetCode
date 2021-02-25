題號: 1402. Reducing Dishes

難度: Hard

## 問題描述
A chef has collected data on the `satisfaction` level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  `time[i]*satisfaction[i]`

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in **any** order and the chef can discard some dishes to get this maximum value.


Example 1:

```
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
```

Constraints:

- `n == satisfaction.length`
- `1 <= n <= 500`
- `-10^3 <= satisfaction[i] <= 10^3`

---
## 解決思路

因為我們知道將越大的滿意度乘上越大的時間可以得大越大的效益，所以此題我們先將`satisfaction`做遞增排序，而後從後面迭代回來做比較。

以此例來說
satisfaction = [-1,-8,0,5,-9]
做排序後
satisfaction = [-9,-8,-1,0,5]


我們令 `sum` = 0, `ret` = 0 
迭代過程:
`ret = max(ret, satisfaction[i] + ret + sum);`
`sum += satisfaction[i];`
想法是若在當前最佳解時前面在插入一個數字，是否會有較大的解?所以我們可以利用sum來保存之前的遍歷的總和。因為在插入新的`satisfaction[i]`後，`satisfaction[i+1] ~ satisfaction[n]`會多一次的和。

在完成所有迭代後，則ret即為最佳解。
