題號: 2402. Meeting Rooms III

難度: `Hard`

## 問題描述

You are given an integer `n`. There are `n` rooms numbered from `0` to `n - 1`.

You are given a 2D integer array `meetings` where `meetings[i] = [start_i, end_i]` means that a meeting will be held during the **half-closed time interval** `[start_i, end_i)`. All the values of `start_i` are **unique**.

Meetings are allocated to rooms in the following manner:

1. Each meeting will take place in the unused room with the **lowest** number.
2. If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the **same** duration as the original meeting.
3. When a room becomes unused, meetings that have an earlier original **start** time should be given the room.

Return the **number** of the room that held the most meetings. If there are multiple rooms, return the room with the **lowest** number.

A **half-closed interval** `[a, b)` is the interval between `a` and `b` **including** `a` and **not including `b`**.




**Example 1:**
```
Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
```
**Constraints:**

- `1 <= n <= 100`
- `1 <= meetings.length <= 10^5`
- `meetings[i].length == 2`
- `0 <= starti < endi <= 5 * 10^5`
- All the values of `start_i` are unique.

**解決思路:**

此題需要準備一個min heap(`room_heap`)用來儲存每個房間的可用時間為`[release time, room id]`，並且要對`meetings`做遞增排序，因為題目要求越早開始的會議應該要優先被排入。

我們可以知道根據題意，排入的會議順序一定是從排序後的`meetings[0] ~ meetings[n-1]`依序找到可用房間執行的。因此我們只需依序迭代`meetings`即可。

對於每個會議，release time小於當前`start`的可用房間都先調整`start`再放回heap。因為對於已經被釋出的房間，我們並不在乎它的釋出時間，只在意編號大小，因此才需要將這些房間的釋出時間重置成`start`對齊。

之後我們就可以直接取出heap top的房間分配可當前的meeting了，而其分配完後的下一次釋放時間就是它的`release_time + end - start`。之後將此房間的使用次數加1即可。

最後我們只需要返回使用次數最多的房間編號。

