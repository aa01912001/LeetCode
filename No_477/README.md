題號: 477. Total Hamming Distance

難度: Medium

## 問題描述

The `Hamming distance` between two integers is the number of positions at which the corresponding bits are different.

Given an integer array `nums`, return the sum of **Hamming distances** between all the pairs of the integers in `nums`.

**Example 1:**


```
Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
```


**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`


---
## 解決思路

此題我們可利用`vector<int> count(32, 0)`來儲存歷史中索引位元出現過1的個數，而當今天我們要判斷一個數`num`時，我們可以將他當前索引位元與`count`去做比較。若`num`當前索引位元為0則將答案加上`count`相對應位置的索引值(此動作代表著`num`同時比較了先前遍歷過的`num`的該位元)，而當`num`的當前索引位元為1時，將答案加上(`i - count[index]`)即可，其中`i`為當前`num`是第幾個遍歷到的。



