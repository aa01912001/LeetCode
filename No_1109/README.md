題號: 1109. Corporate Flight Bookings
難度: Medium

## 問題描述

There are `n` flights that are labeled from `1` to `n`.

You are given an array of flight bookings `bookings`, where `bookings[i] = [firsti, lasti, seatsi]` represents a booking for flights `firsti` through `lasti` (**inclusive**) with `seatsi` seats reserved for **each flight** in the range.

Return an array `answer` of length `n`, where `answer[i]` is the total number of seats reserved for flight `i`.

```
Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
```

**Constraints:**

- `1 <= n <= 2 * 10^4`
- `1 <= bookings.length <= 2 * 10^4`
- `bookings[i].length == 3`
- `1 <= firsti <= lasti <= n`
- `1 <= seatsi <= 10^4`

---
## 解決思路

此題對於每一個`bookings[i][0]` ~ `bookings[i][1]`來說，因為他們所預定的座位數皆與`bookings[i][0]`相同，因此我們可以在解答陣列中的`bookings[i][0]`位置上加上`bookings[i][2]`，最後只要在解答陣列中使用prefix sum就可以將其他班機加上相同的座位。

需要特別注意的是，我們必須在解答陣列中`bookings[i][1]+1`的位置上減去`bookings[i][2]`，如此才能將後續的prefix sum中停止累加該booking所賦予的座位數。

