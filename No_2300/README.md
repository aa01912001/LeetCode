題號: 2300. Successful Pairs of Spells and Potions

難度: Medium

## 問題描述
You are given two positive integer arrays `spells` and `potions`, of length `n` and `m` respectively,  
where `spells[i]` represents the strength of the *iᵗʰ* spell and `potions[j]` represents the strength of the *jᵗʰ* potion.

You are also given an integer `success`.  
A spell and potion pair is considered **successful** if the product of their strengths is **at least** `success`.

Return an integer array `pairs` of length `n` where `pairs[i]` is the number of **potions** that will form a successful pair with the *iᵗʰ* spell.



**Example 1:**
```
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.
```

**Constraints:**

- `n == spells.length`
- `m == potions.length`
- `1 <= n, m <= 10^5`
- `1 <= spells[i], potions[i] <= 10^5`
- `1 <= success <= 10^10`

**解決思路:**

我們只需要對`potions`做sorting，再依序針對每個`spells`的每個元素對`potions`使用binary search來找出最小符合的index即可。