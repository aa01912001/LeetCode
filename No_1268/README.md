題號: 1268. Search Suggestions System
難度: Medium

## 問題描述

You are given an array of strings `products` and a string `searchWord`.

Design a system that suggests at most three product names from `products` after each character of `searchWord` is typed. Suggested products should have common prefix with `searchWord`. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of `searchWord` is typed.
 

**Example 1:**
```
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
```


**Constraints:**

- `1 <= products.length <= 1000`
- `1 <= products[i].length <= 3000`
- `1 <= sum(products[i].length) <= 2 * 10^4`
- All the strings of products are **unique**.
products[i] consists of lowercase English letters.
- `1 <= searchWord.length <= 1000`
- `searchWord` consists of lowercase English letters.

---
## 解決思路

此題首先可藉由Trie的結構來儲存`searchWord`，之後為了保證解答的答案順序為**lexicographically**，我們需要對`products`去作排序，之後從頭開始比對Trie，針對每個product，我們可根據每個比對到字元的索引順序，在`vector<vector<string>>`的結構中相應地插入該字串，而因為我們一開始已經對`products`去作排序，因此，最終解答一定保證**lexicographically**。