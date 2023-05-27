題號: 123. Best Time to Buy and Sell Stock III
難度: Hard

## 問題描述
You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Find the maximum profit you can achieve. You may complete **at most two transactions**.

**Note:** You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**
```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```
**Constraints:**

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`


## 解決思路
假設`prices`為`[3,3,5,0,0,3,1,4]`，我們可以準備兩個長度相同的array:

`maxProfLeft`:用以儲存從左到右至多一次交易於第`i`天賣出的最大利益，因此其內容為`[0,0,2,0,0,3,1,4]`

`maxProfRight`，用以儲存從右到左於至多一次交易於第`i`天買進的最大利益，因此其內容為`[2,2,0,4,4,1,3,0]`

之後我們分別將`maxProfLeft`與`maxProfRight`分別轉換為:

從左到右至多一次交易於第`i`天(含)前的最高利益，因此`maxProfLeft`會變成
`[0,0,2,2,2,3,3,4]`

從右到左至多一次交易於第`i`天(含)後的最高利益，因此`maxProfRight`會變成
`[4,4,4,4,4,3,3,0]`

因為我們知道兩次最佳的交易不會有時間上的交集，因此對於每一天我們可以判斷

`maxProfLeft[i] + maxProfRight[i+1]` (代表`0~i`天的最大利益加上`i+1~n-1`天的最大利益) 是否比當前解答高。