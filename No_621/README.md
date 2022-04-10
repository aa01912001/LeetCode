題號: 621. Task Scheduler
難度: Medium

## 問題描述

Given a characters array `tasks`, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer `n` that represents the cooldown period between two **same tasks** (the same letter in the array), that is that there must be at least `n` units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

**Example 1:**

```
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
```

**Constraints:**

- `1 <= task.length <= 10^4`
- `tasks[i]` is upper-case English letter.
- The integer `n` is in the range `[0, 100]`.


---
## 解決思路

在此題中，我們應該優先處理高頻任務，再接著處理低頻任務。

舉例來說:

task: ACCCEEEE, n: 2

我們每次應該從前n高頻的task中各取一個出來排程，上例為C、E。這是因為越高頻的任務越容易造成需要插入idle，因此我們需要在能有足夠的task時，優先將這些高頻task交錯排程。

在程式中，我們使用max heap將所有種類task之頻率記錄下來，而在每回合中若發現剩餘的種類數(表示為`r`)大於等於`n+1`，那麼就不需要加入idle(代表有足夠多的任務種類可交錯排程)，否則將需要插入`n+1-r`個idle，以滿足當前最高頻的任務之cooldown period。

而之後我們也更新max heap中各種類任務之頻率，若剩餘種類數足夠(`r >= n+1`)，那我們就將max heap中前`n+1`高頻任務種類之頻率各減一，若不足，則只需取前`r`高頻之任務做更新。

Note: 最後一回合即使`r < n+1`也不需要插入idle，因為已無任務於ready queue中。