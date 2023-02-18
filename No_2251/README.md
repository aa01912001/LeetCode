題號: 2251. Number of Flowers in Full Bloom
難度: Hard

## 問題描述
You are given a **0-indexed** 2D integer array `flowers`, where `flowers[i] = [starti, endi]` means the `ith` flower will be in **full bloom** from `starti` to `endi` (**inclusive**). You are also given a **0-indexed** integer array `persons` of size `n`, where `persons[i]` is the time that the `ith` person will arrive to see the flowers.

Return an integer array `answer` of size `n`, where `answer[i]` is the **number** of flowers that are in full bloom when the `ith` person arrives.

**Example 1:**
![](https://i.imgur.com/ym8eg7S.png)
```
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
```

**Constraints:**
- `1 <= flowers.length <= 5 * 10^4`
- `flowers[i].length == 2`
- `1 <= starti <= endi <= 10^9`
- `1 <= persons.length <= 5 * 10^4`
- `1 <= persons[i] <= 10^9`

---
## 解決思路
此題可以基於sweep line的方式來找出所有時間段的開花數量。

因此我們首先必須要對每個`flowers[i]`記錄其花開花謝事件，舉例來說，`flowers[i][0]`時間點花的數量會加1，`flowers[i][1]+1`花的數量會減1。

再找出所有的事件pair(day, diff)並依時間排序後，我們便能依據`persons`的抵達時間由小至大的找出所有相應時間點的花的數量。