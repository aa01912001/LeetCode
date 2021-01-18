題號: 134. Gas Station

難度: Medium

## 問題描述
There are `n` gas stations along a circular route, where the amount of gas at the `ith` station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `ith` station to its next `(i + 1)th` station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return `-1`. If there exists a solution, it is **guaranteed** to be **unique**

Example 1:
```
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

Constraints:
- `gas.length == n`
- `cost.length == n`
- `1 <= n <= 10^4`
- `0 <= gas[i], cost[i] <= 10^4`

---
## 解決思路
此題我們利用一`total`變數來儲存所有的gas扣掉cost之值，以便來判斷是否有可能的解，若total<0則表示車子根本不可能有辦法繞一圈。此外需要利用一個`cur`變數來記錄當前所剩餘的gas有多少，和使用`start`變數來記錄當前的起始位置，一旦發現cur<0則表示先前紀錄在start中的起始位置是不可能成功的，而途中經過的位置也不可能當作起始位置(**因為途中的位置若能執行成功，那麼先前的起始位置也必能成功，所以會產生矛盾現象**)，所以必須更新新的起始位置為`i+1`和將cur重設為0來重新計算此起始位置的可能性。我們不必擔心最後一個位置cur是否有被計算，因為total中的值相當於對最後一個位置的cur計算。