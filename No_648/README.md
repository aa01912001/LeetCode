題號: 648. Replace Words

難度: Medium

## 問題描述

In English, we have a concept called **root**, which can be followed by some other word to form another longer word - let's call this word **successor**. For example, when the **root** `"an"` is followed by the **successor** word `"other"`, we can form a new word `"another"`.

Given a `dictionary` consisting of many **roots** and a `sentence` consisting of words separated by spaces, replace all the **successors** in the sentence with the **root** forming it. If a **successor** can be replaced by more than one **root**, replace it with the **root** that has **the shortest length**.

Return the `sentence` after the replacement.

Example 1:

```
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```

Constraints:

- `1 <= dictionary.length <= 1000`
- `1 <= dictionary[i].length <= 100`
- `dictionary[i]` consists of only lower-case letters.
- `1 <= sentence.length <= 10^6`
- `sentence` consists of only lower-case letters and spaces.
- The number of words in `sentence` is in the range `[1, 1000]`
- The length of each word in `sentence` is in the range `[1, 1000]`
- Each two consecutive words in `sentence` will be separated by exactly one space.
- `sentence` does not have leading or trailing spaces.



---
## 解決思路

此題我們先將`dictionary`中的roots用`unordered_set<string>`儲存起來，以便之後用於比對。之後將`sentence`以空白符號做split後，分別去替換每一個word。針對每一個word我們從開頭最短的子字串到最長的子字串去與`unordered_set<string>`中的roots比對，若比對到則替換之。對於每個word經由上述步驟後即可得到解答。