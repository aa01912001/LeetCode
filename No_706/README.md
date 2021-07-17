題號: 706. Design HashMap

難度: Easy

## 問題描述

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:


- `MyHashMap()` initializes the object with an empty map.
- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.
- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.
- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.


**Example 1:**

```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```


**Constraints:**

- `0 <= key, value <= 10^6`
- At most `10^4` calls will be made to `put`, `get`, and `remove`.

---
## 解決思路

此題我們可利用`vector<int>`來當作hashmap，因為題目限制了key、value的範圍為`0~10^6`所以我們只需初始化vector為長度`1000001`且值為`-1`即可。



