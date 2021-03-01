題號: 841. Keys and Rooms

難度: Medium

## 問題描述
There are `N` rooms and you start in room `0`.  Each room has a distinct number in `0, 1, 2, ..., N-1`, and each room may have some keys to access the next room. 

Formally, each room `i` has a list of keys `rooms[i]`, and each key `rooms[i][j]` is an integer in `[0, 1, ..., N-1]` where `N = rooms.length`.  A key `rooms[i][j] = v` opens the room with number `v`.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return `true` if and only if you can enter every room.

Example 1:

```
Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
```

Note:

- `1 <= rooms.length <= 1000`
- `0 <= rooms[i].length <= 1000`
- The number of keys in all rooms combined is at most `3000`

---
## 解決思路

我們可以將`rooms`視為一張圖，其中頂點為`0~N`，而`rooms[i][j]`為邊。如此我們就可以利用DFS來遍歷整張圖，同時利用`visited`陣列來儲存每個房間是否已經被開啟過的狀況。最後只要判斷`visited[i]`是否皆為true即可。