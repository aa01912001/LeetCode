題號: 1371. Find the Longest Substring Containing Vowels in Even Counts
難度: Medium

## 問題描述

Given the string `s`, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

**Example 1:**
```
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
```

**Constraints:**

- `1 <= s.length <= 5 x 10^5`
- `s` contains only lowercase English letters.

---
## 解決思路

此題我們必須記錄每個a、e、i、o、u從index 0出現次數之奇偶組合最出現於哪個index，例如：

[奇、奇、偶、奇、偶]此組合最早出現在index 3中，若我們在index 10中同樣出現此奇偶組合，那麼我們可以斷定index 4 ~ index 10中a、e、i、o、u皆只出現偶數次，因此該子字串長度為10-4 = 6。

程式中，我們以整數(存於變數`mask`)來紀錄每個索引當前的奇偶組合，即：

```
int shift = s[i] - 'a';
mask ^= (1 << shift);
```
因此只需要在`unordered_map<int, int>`中判斷`mask`是否存在，若不存在就將此`mask`與index紀錄於map中即可，否則判斷當前index與`mask`第一次出現之index進行相減，並判斷是否為最大長度。

