題號: 2860. Happy Students

難度: Medium

## 問題描述
You are given a **0-indexed** integer array `nums` of length `n` where `n` is the total number of students in the class. The class teacher tries to select a group of students so that all the students remain happy.

The `ith` student will become happy if one of these two conditions is met:

- The student is selected and the total number of selected students is **strictly greater than** `nums[i]`.

- The student is not selected and the total number of selected students is **strictly less than** `nums[i]`.

Return the number of ways to select a group of students so that everyone remains happy.

**Example 1:**
```
Input: nums = [6,0,3,3,6,7,2,7]
Output: 3
Explanation: 
The three possible ways are:
The class teacher selects the student with index = 1 to form the group.
The class teacher selects the students with index = 1, 2, 3, 6 to form the group.
The class teacher selects all the students to form the group.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] < nums.length`


**解決思路:**

假設某個挑選學生的數量`x`可以滿足規則，我們知道對於具有相同`nums[i]`那些學生只會有兩個可能性:

1. 同時存在於被挑選的group中
2. 同時沒被挑選到

我們可以針對`nums`先進行排序，並且從頭開始尋找哪些index i可以滿足`nums[i-1] < i + 1 < nums[i+1]`。

其中`i + 1`為被挑選的學生總數，位於`i`左邊的學生都是位於此group中，位於`i`右邊的學生反之。

我們知道只要`nums[i-1] < i + 1`，`nums[0] ~ nums[i-2]`也必定會小於`i + 1`，對於`nums[i+1]~nums[n-1]`同理。

因此只要找到滿足的`index i`，我們就將解答值加1。另外對於所有學生皆不選或皆選的情況則另外判斷`nums[0] != 0`與`nums[n-1] < n`即可。