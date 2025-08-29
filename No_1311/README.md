題號: 1311. Get Watched Videos by Your Friends

難度: Medium

## 問題描述
There are `n` people, each person has a unique id between `0` and `n-1`. Given the arrays `watchedVideos` and `friends`, where `watchedVideos[i]` and `friends[i]` contain the list of watched videos and the list of friends respectively for the person with `id = i`.

Level **1** of videos are all watched videos by your friends, level **2** of videos are all watched videos by the friends of your friends and so on. In general, the level `k` of videos are all watched videos by people with the shortest path **exactly** equal to `k` with you. Given your `id` and the `level` of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 

**Example 1:**
![leetcode_friends_1](https://hackmd.io/_uploads/HyxFbACYee.png)
```
Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
Output: ["B","C"] 
Explanation: 
You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
Person with id = 1 -> watchedVideos = ["C"] 
Person with id = 2 -> watchedVideos = ["B","C"] 
The frequencies of watchedVideos by your friends are: 
B -> 1 
C -> 2
```

**Constraints:**

- `n == watchedVideos.length == friends.length`
- `2 <= n <= 100`
- `1 <= watchedVideos[i].length <= 100`
- `1 <= watchedVideos[i][j].length <= 8`
- `0 <= friends[i].length < n`
- `0 <= friends[i][j] < n`
- `0 <= id < n`
- `1 <= level < n`
- if `friends[i]` contains `j`, then `friends[j]` contains `i`

**解決思路:**

此題我們透過三個步驟來執行:

1. BFS 找到 level k 的朋友:
    - 使用`visited`來儲存已經遍歷過的人，因此每個人最多會被放進 queue 一次
    - 每條朋友關係（邊）最多檢查一次。
    - 時間複雜度是 O(N + E)，其中:
        - N = 人數
        - E = 總朋友關係數（邊數）

2. 使用Counter來統計影片的frequency:
    - 遍歷 BFS 結束後的所有朋友，假設他們一共看了 M 部影片（可能有重複）。
    - 更新 Counter 需要 O(M)。

3. 排序影片
    - 最多要排序 D 部不同的影片（D ≤ M）。
    - 排序時間複雜度是 O(D log D)。


因此:
- 時間複雜度為: O(N+E+M+DlogD)
- 空間複雜度: O(N+D)
    - visited 和 queue → 最多 O(N)
    - Counter → O(D)