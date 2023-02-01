題號: 2222. Number of Ways to Select Buildings
難度: Medium

## 問題描述
You are given a **0-indexed** binary string `s` which represents the types of buildings along a street where:

- `s[i] = '0'` denotes that the `ith` building is an office and
- `s[i] = '1'` denotes that the `ith` building is a restaurant.

As a city official, you would like to **select** 3 buildings for random inspection. However, to ensure variety, **no two consecutive** buildings out of the **selected** buildings can be of the same type.

- For example, given `s = "001101"`, we cannot select the `1st`, `3rd`, and `5th` buildings as that would form `"011"` which is not allowed due to having two consecutive buildings of the same type.

Return the **number of valid ways** to select 3 buildings.

**Example 1:**
```
Input: s = "001101"
Output: 6
Explanation: 
The following sets of indices selected are valid:
- [0,2,4] from "001101" forms "010"
- [0,3,4] from "001101" forms "010"
- [1,2,4] from "001101" forms "010"
- [1,3,4] from "001101" forms "010"
- [2,4,5] from "001101" forms "101"
- [3,4,5] from "001101" forms "101"
No other selection is valid. Thus, there are 6 total ways.
```

**Constraints:**

- `3 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

---
## 解決思路
此題我們只需要把每一棟為中間建築的可能個數加總起來即為答案。

因此我們可以分別計算`'0'`與`'1'`個數之prefix sum後，就可以輕易算出`s[i]`為中間建築時的所有可能個數。

例如`s[i]`為`'0'`，其個數為`preSumOne[i-1] * (preSumOne[n-1] - preSumOne[i])`，其中`n`為`s`長度;而`s[i]`為`'1'`時的計算方式亦同。