題號: 3016. Minimum Number of Pushes to Type Word II
難度: Medium

## 問題描述
You are given a string `word` containing lowercase English letters.

Telephone keypads have keys mapped with **distinct** collections of lowercase English letters, which can be used to form words by pushing them. For example, the key `2` is mapped with `["a","b","c"]`, we need to push the key one time to type `"a"`, two times to type `"b"`, and three times to type `"c"`.

It is allowed to remap the keys numbered `2` to `9` to **distinct** collections of letters. The keys can be remapped to **any** amount of letters, but each letter **must** be mapped to **exactly** one key. You need to find the **minimum** number of times the keys will be pushed to type the string `word`.

Return the **minimum** number of pushes needed to type `word` after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that `1`, `*`, `#`, and `0` do **not** map to any letters.

![image](https://hackmd.io/_uploads/SyjkMNk50.png)


**Example 1:**
![image](https://hackmd.io/_uploads/S1VxfVkc0.png)
```
Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
```

**Constraints:**

- `1 <= word.length <= 10^5`
- `word` consists of lowercase English letters.

## 解決思路
此題我們對於`word`記錄每個字元的出現頻率，並且我們知道將出現頻率越大的字元放在按鍵的越前面就可形成越小的解答。

按照此greedy的想法，我們針對每個字元的出現頻率做遞減排序後，依序取出，將解答值加上 `出現頻率 ＊ 每個當前字元需要按下的次數` 即可。

一開始迭代的時候字元需要按下的次數為1，直到每8(按鍵的個數)個不同的字元放完一層後，爾後的字元按下的次數才需要加1。