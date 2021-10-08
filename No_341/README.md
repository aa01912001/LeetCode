題號: 341. Flatten Nested List Iterator

難度: Medium

## 問題描述

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

- `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.

- `int next()` Returns the next integer in the nested list.

- `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

Your code will be tested with the following pseudocode:

```
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
```

If `res` matches the expected flattened list, then your code will be judged as correct.

**Example 1:**

```
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```

**Constraints:**

- `1 <= nestedList.length <= 500`
- The values of the integers in the nested list is in the range `[-10^6, 10^6]`.


---
## 解決思路

此題我們需要將`nestedList`利用DFS策略將整數依序存放進`queue<int>`，之後就可以利用此queue是否為空來檢查有下一個元素並取出。


