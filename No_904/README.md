題號: 904. Fruit Into Baskets

難度: Medium

## 問題描述
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the **type** of fruit the `ith` tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:


- You only have **two** baskets, and each basket can only hold a **single type** of fruit. There is no limit on the amount of fruit each basket can hold.

- Starting from any tree of your choice, you must pick **exactly one fruit** from **every** tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.

- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array `fruits`, return the **maximum** number of fruits you can pick.

**Example 1:**
```
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
```

**Constraints:**

- `1 <= fruits.length <= 10^5`
- `0 <= fruits[i] < fruits.length`

**解決思路:**

此題是典型的sliding window題型，我們需要找出最大的子陣列區間，其中只包含兩種type。

因此我們可以讓右邊界不斷遞進，同時計算每種type的數量。一但我們發現當前區間包含超過2種的type，我們就需要開始遞進左邊界，直到type數量<=2即可。