題號: 1130. Minimum Cost Tree From Leaf Values

難度: Medium

## 問題描述

Given an array `arr` of positive integers, consider all binary trees such that:

- Each node has either `0` or `2` children;
- The values of `arr` correspond to the values of each **leaf** in an in-order traversal of the tree.
- The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a **32-bit** integer.

A node is a **leaf** if and only if it has zero children.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/08/10/tree1.jpg)

```
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
```

**Constraints:**

- `2 <= arr.length <= 40`
- `1 <= arr[i] <= 15`
- It is guaranteed that the answer fits into a **32-bit** signed integer (i.e., it is less than 2^31).

---
## 解決思路

此題我們可利用dynamic programming的策略去解，在程式中我們首先計算出一個二維陣列`mx`以便之後取得範圍最大葉節點值。

其中`mx[i][j]`儲存了`arr[i]`至`arr[j]`的最大葉節點值。

而另一個二維陣列`dp`是為了避免重複計算重複的範圍Minimum Cost Tree。

其中`dp[i][j]`儲存了`arr[i]`至`arr[j]`的Minimum Cost Tree。

當我們今天要計算`dp[s][e]`時，我們可以將這個範圍內的葉節點分為位於左邊子樹的葉節點與右邊子樹的葉節點，因此左子樹群可能的範圍即為`s~i`，右子樹群為`i+1~e`，`i: s~e-1`(因為題目限制子節點個數必為0或2，所以`i`不可能為`e`)。

因此我們即可利用遞迴搭配`dp`來避免重複計算相同的Minimum Cost Tree，以取得最終的Minimum Cost Tree。









