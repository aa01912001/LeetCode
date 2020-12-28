題號: 49. Group Anagrams

難度: Medium

## 問題描述
Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

Constraints:
* `1 <= strs.length <= 104`
* `0 <= strs[i].length <= 100`
* `strs[i] consists of lower-case English letters.`

---
## 解決思路
此題可以使用`unordered_map<string, vector<string>>`來儲存每個anagram類的組員，我們在遍歷每個string時先將該string做sort(**相同anagram做sort後的結果會相同**)來判斷map中是否已經有相同的anagram。若有，則插入該類anagram之vector後面，若無，則新增一個anagram類至map中(**其中key值為該sort後的string**)。最後只要把map中的每組`vector<string>`取出放入`vector<vector<string>>`中返回即可。
