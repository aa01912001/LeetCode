題號: 946. Validate Stack Sequences

難度: Medium

## 問題描述
Given two sequences `pushed` and `popped` **with distinct values**, return `true` if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:

```
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

Constraints:


- `0 <= pushed.length == popped.length <= 1000`
- `0 <= pushed[i], popped[i] < 1000`
- `pushed` is a permutation of `popped`.
- `pushed` and `popped` have distinct values.

---
## 解決思路
此題我們需要依序從`pushed`中依序找到`popped[i]`值，在找尋的過程中，若`pushed[index]`不等於`popped[i]`，則將之push到stack中。而在每次找尋的一開始必須要檢查stack top是否等於`popped[i]`，若是的話則直接pop出即可。若發現`pushed`中的數皆已push到stack中過，而stack top又不等於`popped[i]`，則代表陷入deadlock，表示此**stack sequence**是不合法的，必須返回`false`。若最後成功將所有`pushed`中的數從stack中pop出，則代表此為合法的**stack sequence**，則返回`true`。