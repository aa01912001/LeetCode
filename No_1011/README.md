題號: 1011. Capacity To Ship Packages Within D Days

難度: Medium

## 問題描述
A conveyor belt has packages that must be shipped from one port to another within `D` days.

The ith package on the conveyor belt has a weight of `weights[i]`. Each day, we load the ship with packages on the conveyor belt (in the order given by `weights`). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within `D` days.

Example 1:

```
Input: weights = [1,2,3,4,5,6,7,8,9,10], D = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
```

Constraints:

- `1 <= D <= weights.length <= 5 * 10^4`
- `1 <= weights[i] <= 500`

---
## 解決思路
此題需要利用binary search的方式來找出解答，首先令`left =  0`、`right = sum of weights`後再開始從中間的值來判斷此capacity是否可以在D days內完成。所以我們需要有一個`determine`的函示來幫助判斷是否可完工。如此透過binary search的方式即可找出minimum capacity。