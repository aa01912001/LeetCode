題號: 56. Merge Intervals

難度: Medium

## 問題描述
Given an array of `intervals` where `intervals[i]` = [$start_i,\ end_i$], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

---
## 解決思路
首先將intervals用sort()排序之。
並使用start、end變數來維護下一個要被放入解答的interval之start與end。

我們可以觀察到各相鄰之interval有兩種情況:
1. **重疊的情況**-使用 **end = max(previous end, next end)** 更新目前的end即可。
2. **沒重疊的情況**-直接將前一個interval放入解答中，並更新目前的start與end為下一個interval。

Note: 其中，重疊的情況又可分為**下一個interval被包含在前一個interval中**與**下一個interval部分被包含在前一個interval中**，我們只需判斷前一個的end與下一個的end哪個比較大即可。


