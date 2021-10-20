題號: 895. Maximum Frequency Stack

難度: Hard

## 問題描述

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the `FreqStack` class:
- `FreqStack()` constructs an empty frequency stack.
- `void push(int val)` pushes an integer `val` onto the top of the stack.
- `int pop()` removes and returns the most frequent element in the stack.
    - If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

**Example 1:**

```
Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```

**Constraints:**

- `0 <= val <= 10^9`
- At most `2 * 10^4` calls will be made to `push` and `pop`.
- It is guaranteed that there will be at least one element in the stack before calling `pop`.

---
## 解決思路

此題我們需要準備`unordered_map<int, int>`與`unordered_map<int, stack<int>>`，分別為:

`frequency`用來儲存每個數當前的頻率。
`frequencyStack`用來儲存當前各個數抵達此頻率時被放入stack的順序。

另外我們使用`int maxFreq`來儲存目前所有數中最大的頻率。

在`push`當中:

我們將`val`的頻率更新，並更新`maxFreq`與`frequencyStack`。

而當`pop`時:

我們必須取出`frequencyStack[maxFreq].top()`來返回，因為必須返回最大頻率的數。後再接著更新欲返回數的當前頻率與`maxFreq`即可。






