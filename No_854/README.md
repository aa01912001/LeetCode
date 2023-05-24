題號: 854. K-Similar Strings
難度: Hard

## 問題描述
Strings `s1` and `s2` are `k`**-similar** (for some non-negative integer `k`) if we can swap the positions of two letters in `s1` exactly `k` times so that the resulting string equals `s2`.

Given two anagrams `s1` and `s2`, return the smallest `k` for which `s1` and `s2` are `k`**-similar**.

**Example 1:**
```
Input: s1 = "abc", s2 = "bca"
Output: 2
Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
```
**Constraints:**

- `1 <= s1.length <= 20`
- `s2.length == s1.length`
- `s1` and `s2` contain only lowercase letters from the set `{'a', 'b', 'c', 'd', 'e', 'f'}`.
- `s2` is an anagram of `s1`.

## 解決思路
此題我們可以利用BFS的方法來求將`A`進行一連串swap到`B`的最短路徑。

假設A = acbaa, B = aacba

我們首先找到A與B第一個不同字元的位置`i = 1`，之後我們必須將A之後字元等於B[i]的位置j與A[i]進行交換，因此我們可以得到下列兩個可能性:

aabca
aabac

以上兩組就是我們第一層BFS可找到的路徑，之後以同樣的方式繼續進行BFS搜尋，最終就可抵達aacba的目的地。

另外程式中我們利用`unordered_set<string>`將搜尋過的字串紀錄以來，以防後續有重複的字串被走訪。

