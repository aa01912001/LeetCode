題號: 1024. Video Stitching
難度: Medium

## 問題描述

You are given a series of video clips from a sporting event that lasted `time` seconds. These video clips can be overlapping with each other and have varying lengths.

Each video clip is described by an array `clips` where `clips[i] = [starti, endi]` indicates that the ith clip started at `starti` and ended at `endi`.

We can cut these clips into segments freely.

- For example, a clip `[0, 7]` can be cut into segments `[0, 1] + [1, 3] + [3, 7]`.

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event `[0, time]`. If the task is impossible, return `-1`.

**Example 1:**
```
Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10
Output: 3
Explanation: We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
```

**Constraints:**

- `1 <= clips.length <= 100`
- `0 <= starti <= endi <= 100`
- `1 <= time <= 100`


---
## 解決思路

此題我們可以準備一個DP陣列，其中`dp[i]`代表，`time`為`i`時所需的最少clip數。

一開始，我們需要先將`clips`做排序，以便之後將其中之clip按照時序做處理，之後，從頭開始針對每個clip中的時間去找出其dp之解，其狀態轉移式如下：

`dp[j] = min(dp[j], dp[clips[i][0]]+1)`

其中，`j`為`clips[i][0]`~`clips[i][1]`時間段中的某一時刻，且所有`dp[i]`之初始值為`INT_MAX`。

上敘式子代表`time`等於`j`時所需的最少clip數可能由`time`等於`dp[clips[i][0]]`時之所需最少clip數加上當前clip所組成，或著時刻`j`已經包含在先前某個clip中，因此不需要加上當前clip。

最後只要返回`dp[time]`即為正確答案。