題號: 1404. Number of Steps to Reduce a Number in Binary Representation to One
難度: Medium

## 問題描述

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

- If the current number is even, you have to divide it by `2`.
- If the current number is odd, you have to add `1` to it.

**Example 1:**
```
Input: s = "1101"
Output: 6
Explanation: "1101" corressponds to number 13 in their decimal representation.
Step 1) 13 is odd, add 1 and obtain 14. 
Step 2) 14 is even, divide by 2 and obtain 7.
Step 3) 7 is odd, add 1 and obtain 8.
Step 4) 8 is even, divide by 2 and obtain 4.  
Step 5) 4 is even, divide by 2 and obtain 2. 
Step 6) 2 is even, divide by 2 and obtain 1.  
```


**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of characters '0' or '1'
- `s[0] == '1'`

---
## 解決思路

此題我們可針對`s`從右到左去計算每一段連續`1`的個數，假設某一段的連續`1`個數為`cnt`，那麼遇到`0`之後我們就將答案加上`cnt+1`(其中有`cnt`次的規則一，`1`次的規則二)，而這段連續`1`加1後會導致當前的0也變成1，因此我們需要將`cnt`變數重置為0，如下所示：

`0` `111...111` + 1
會變成
`1` `000...000`

而對於其他那些`s`中不會因溢位變成`1`的`0`來說，我們就單純將解答值加1(規則一)即可，如此即可得到最終解答。
