題號: 1665. Minimum Initial Energy to Finish Tasks
難度: Hard

## 問題描述
You are given an array `tasks` where `tasks[i] = [actual_i, minimum_i]`:

- `actual_i` is the actual amount of energy you **spend to finish** the `ith` task.
- `minimum_i` is the minimum amount of energy you **require to begin** the `ith` task.

For example, if the task is `[10, 12]` and your current energy is `11`, you cannot start this task. However, if your current energy is `13`, you can complete this task, and your energy will be `3` after finishing it.

You can finish the tasks in **any order** you like.

Return the **minimum** initial amount of energy you will need to finish all the tasks.

**Example 1:**
```
Input: tasks = [[1,2],[2,4],[4,8]]
Output: 8
Explanation:
Starting with 8 energy, we finish the tasks in the following order:
    - 3rd task. Now energy = 8 - 4 = 4.
    - 2nd task. Now energy = 4 - 2 = 2.
    - 1st task. Now energy = 2 - 1 = 1.
Notice that even though we have leftover energy, starting with 7 energy does not work because we cannot do the 3rd task.
```

**Constraints:**

- `1 <= tasks.length <= 10^5`
- `1 <= actual_i <= minimumi <= 10^4`

**解決思路:**
此題我們必須採用Greedy的思路來考慮甚麼樣的執行順序才會是最佳的?

每次完成一個task後，我們會希望盡量多留一些energy給後續的task使用，因此我們可以針對每個task t的`t[1] - t[0]`，來做排序，剩餘越多的task我們優先執行。

排序完後，我們從頭遍歷`tasks`，並初始化當前剩餘能量(`remaining`)和解答值為0。

若當前`remaining < tasks[i][1]`，代表我們一開始準備的能量不足，因此將解答值加上`tasks[i][1] - remaining`，並將`remaining`重設為`tasks[i][1] - tasks[i][0]`。

若當前`remaining >= tasks[i][1]`，代表能量是足夠的，我們將`remaining - tasks[i][0]`，留給後續的task使用。



