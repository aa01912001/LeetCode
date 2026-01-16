題號: 2975. Maximum Square Area by Removing Fences From a Field

難度: `Medium`

## 問題描述

There is a large `(m − 1) × (n − 1)` rectangular field with corners at `(1, 1)` and `(m, n)` containing some horizontal and vertical fences given in arrays `hFences` and `vFences` respectively.

Horizontal fences are from the coordinates `(hFences[i], 1)` to `(hFences[i], n)` and vertical fences are from the coordinates `(1, vFences[i])` to `(m, vFences[i])`.

Return the **maximum** area of a **square** field that can be formed by **removing** some fences (**possibly none**) or `-1` if it is impossible to make a square field.

Since the answer may be large, return it **modulo** `10^9 + 7`.

**Note**: The field is surrounded by two horizontal fences from the coordinates `(1, 1)` to `(1, n)` and `(m, 1)` to `(m, n)` and two vertical fences from the coordinates `(1, 1)` to `(m, 1)` and `(1, n)` to `(m, n)`. These fences cannot be removed.

**Example 1:**
![圖片](https://hackmd.io/_uploads/rku8QTPHbx.png)
```
Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
```
**Constraints:**

- `3 <= m, n <= 10^9`
- `1 <= hFences.length, vFences.length <= 600`
- `1 < hFences[i] < m`
- `1 < vFences[i] < n`
- `hFences` and `vFences` are unique.

**解決思路:**

透過觀察，不難看出其實就是我們要找出垂直與水平兩者皆存在的可能形成之最大邊長。

而由於題目給定的`hFences`及`vFences`都很小，所以我們可以很暴力的直接求出兩個方向所有可能形成的邊長。之後取交集中最大的那個邊長來形成正方形即可，若交集為空，則返回-1。