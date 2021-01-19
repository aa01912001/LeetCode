題號: 1094. Car Pooling

難度: Medium

## 問題描述
You are driving a vehicle that has `capacity` empty seats initially available for passengers.  The vehicle **only** drives east (ie. it **cannot** turn around and drive west.)

Given a list of `trips`, `trip[i] = [num_passengers, start_location, end_location]` contains information about the `i`-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return `true` if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Example 1:
```
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
```

Example 2:
```
Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
```

Constraints:

- `trips.length <= 1000`
- `trips[i].length == 3`
- `1 <= trips[i][0] <= 100`
- `0 <= trips[i][1] < trips[i][2] <= 1000`
- `1 <= capacity <= 100000`

---
## 解決思路
因為trips的長度只有1000，所以我們可以用一個長度為0~1000的vector來維護每個地點乘客上車的數量或下車的數量。記錄完後再利用一for loop來從頭開始計算每個時間點的乘客人數有多少，若發現大於capacity則return false。