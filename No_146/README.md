題號: 146. LRU Cache
難度: Medium

## 問題描述
Design a data structure that follows the constraints of a **Least Recently Used (LRU) cache**.

Implement the `LRUCache` class:

- `LRUCache(int capacity)` Initialize the LRU cache with positive size `capacity`.
- `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.
- `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, evict the least recently used key.

The functions `get` and `put` must each run in `O(1)` average time complexity.

**Example 1:**
```
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
```

**Constraints:**

- `1 <= capacity <= 3000`
- `0 <= key <= 10^4`
- `0 <= value <= 10^5`
- At most `2 * 10^5` calls will be made to `get` and `put`.

---
## 解決思路

此題我們可利用`list<pair<int, int>>`來記錄每個當前LRU Cache中的`key-value pair`，其中list越靠近head的節點代表越近期加入Cache中。
另外我們也維護一個`unordered_map<int, list<pair<int, int>>::iterator>`結構來儲存每個list節點的位置，以便之後進行O(1)的隨機存取。

在`get`中，若`key`存在則將其在list中的節點轉移至list最前端，否則返回-1。

在`put`中，若`key`存在則將其在list中的節點轉移至list最前端並且更新其`value`值，否則，若Cache已滿，則將list最後的節點刪除，並新增新節點至list前端，若Cache尚未滿，則直接新增新節點至list前端，