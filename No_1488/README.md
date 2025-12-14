題號: 1488. Avoid Flood in The City

難度: `Medium`

## 問題描述

Your country has \(10^9\) lakes. Initially, all the lakes are empty, but when it rains over the \(n\)th lake, the \(n\)th lake becomes full of water. If it rains over a lake that is **full of water**, there will be a **flood**. Your goal is to avoid floods in any lake.

Given an integer array `rains` where:

- `rains[i] > 0` means there will be rains over the `rains[i]` lake.
- `rains[i] == 0` means there are no rains this day and you **must choose one lake this day and dry it**.

Return an array `ans` where:

- `ans.length == rains.length`
- `ans[i] == -1` if `rains[i] > 0`
- `ans[i]` is the lake you choose to dry in the `i`th day if `rains[i] == 0`

If there are multiple valid answers, return **any of them**.  
If it is impossible to avoid flood, return an **empty array**.

**Notice** that if you choose to dry a full lake, it becomes empty, but if you choose to dry an empty lake, nothing changes.


**Example 1:**
```
Input: rains = [1,2,0,0,2,1]
Output: [-1,-1,2,1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.
```
**Constraints:**

- `1 <= rains.length <= 10^5`
- `0 <= rains[i] <= 10^9`



**解決思路:**

我們可以很清楚知道，假設當前已經有`full_lakes = {x1, x2, ... ,xn}`的lake是滿的，一旦我們遇到0(可抽乾湖的日子)，我們就必須挑選`full_lakes`裡面最早在未來出現的那個優先抽乾，因此我們必須先計算`next_rain`，其中`next_rain[i]`代表`rains[i]`下一次最早出現的位置(如果`rains[i]`為0的話我們直接將`next_rain[i]`設為`len(rain)`，表示未來不會再出現)。

之後我們開始從頭對`rains`遍歷，並維護下列兩個結構:
1. `full_lakes` (set)
    - 紀錄目前已經裝滿水的湖
    - 用來 O(1) 檢查是否發生洪水
2. `urgent_lakes (min heap)`
    - 儲存 (next_rain_index, lake)
    - 用來找出最急著要被抽乾的湖

若`rains[i] > 0`:
    - 如果該湖已經是滿的(存在於`full_lakes`)，代表一定淹水，直接回傳空陣列
    - 若湖是空的，將湖加入`full_lakes`，且將`(next_rain[i], lake)`放入`urgent_lakes`
    
若`rains[i] == 0`:
    - 若`urgent_lakes`不為空，則pop出`next_rain`最小的湖抽乾，並將該湖從`full_lakes`中刪除
    - 若`urgent_lakes`為空，任意抽乾一個湖即可（例如 1）