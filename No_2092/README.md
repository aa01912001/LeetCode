題號: 2092. Find All People With Secret

難度: `Hard`

## 問題描述

You are given an integer **n** indicating there are **n** people numbered from `0` to `n - 1`. You are also given a **0-indexed 2D integer array** `meetings` where `meetings[i] = [xi, yi, timei]` indicates that person `xi` and person `yi` have a meeting at `timei`. A person may attend **multiple meetings at the same time**. Finally, you are given an integer `firstPerson`.

Person `0` has a secret and initially shares the secret with a person `firstPerson` at time `0`. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person `xi` has the secret at `timei`, then they will share the secret with person `yi`, and vice versa.

The secrets are shared **instantaneously**. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a **list of all the people** that have the secret after all the meetings have taken place. You may return the answer in **any order**.

**Example 1:**
```
Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
```
**Constraints:**

- `2 <= n <= 10^5`
- `1 <= meetings.length <= 10^5`
- `meetings[i].length == 3`
- `0 <= xi, yi <= n - 1`
- `xi != yi`
- `1 <= timei <= 10^5`
- `1 <= firstPerson <= n - 1`

**解決思路:**

此題我們可透過Union-Find的方式來解決。

1. 初始狀態與排序:
首先，我們初始化一個 `parents` 陣列。
 - 將 0 和 firstPerson 的狀態設為 -2，代表他們是「秘密的根源」。
 - 將`meetings`按時間從小到大排序，因為秘密是隨著時間流逝而傳遞的，早期的會議結果會影響後期的會議。


2. 如何同一時間點的「瞬間傳遞」:
我們使用 while 將 相同 `curr_time` 的所有會議一起處理。
- 透過`union(u, v)`，合併所有參與者
- 如果這個圈子裡有任何一個人本來就知道秘密（根節點是 -2），那麼這整個圈子的人都會在 find 的過程中與秘密連通。
- 處理完同一個時間點的所有會議後，我們必須檢查該時段的所有參與者（`attendees`）
    - 利用 _find_parent(p) 找到每個人的root。
    - 如果他們的root不是 -2，代表這個人在這個時間點都沒接觸到知道秘密的人。
    - 我們將這些人的 `parents[p]` 設回 -1

處理完所有會議後，我們只需要將root為-2的所有人加入至解答中即可。