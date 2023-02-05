題號: 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
難度: Medium

## 問題描述
You are given an array of integers `arr` and an integer `target`.

You have to find **two non-overlapping sub-arrays** of `arr` each with a sum equal `target`. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is **minimum**.

Return the minimum sum of the lengths of the two required sub-arrays, or return `-1` if you cannot find such two sub-arrays.

**Example 1:**
```
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 1000`
- `1 <= target <= 10^8`

---
## 解決思路
此題解法如下:

1. 利用DP紀錄`arr[i]`之前出現過的sum為target之最小子陣列長度。
2. 對於每個index i，找到左邊離他最近的index j，其中子陣列j~i和為target。
3. 比較當前解答與`i-j+1` + `dp[j-1]`

對於步驟一，我們可以利用一個變數`curMinLen`來儲存先前利用sliding window找到的sum為target之最小子陣列長度，並在每回合的當前索引`i`更新其`dp[i]` 。

因為我們發現`arr[i]`皆為正數，因此步驟二我們只要利用sliding window的方式就可以以線性時間找出所有sum為target之子陣列。

最後步驟三即為將當前子陣列長度加上先前找到的非重疊最短子陣列長度相加後，與當前解答取最小值進行解答更新。