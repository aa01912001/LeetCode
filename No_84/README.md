題號: 84. Largest Rectangle in Histogram

難度: Hard

## 問題描述

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return the area of the largest rectangle in the histogram.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)

```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```

**Constraints:**

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`



---
## 解決思路

此題可利用monotone stack的方式來解，我們利用一個`stack<int>`來儲存那些逐漸上升高度的bar，一旦發現新的bar的高度小於stack的top，我們就將top取出並比較當前最大面積與包含該bar高度所能夠延伸行成的最大面積(**i.e. ret = max(ret, heights[cur]*(i-s.top()-1))**)。

在程式一開始我們在`heights`中push_back(0)以保證最小高度所能夠延伸的最大面積能夠被計算到，並在stack最底部放入-1以確保迴圈跳出。而`stack<int>`儲存的是bar的索引值而並非高度以計算寬度。


