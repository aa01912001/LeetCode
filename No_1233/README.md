題號: 1233. Remove Sub-Folders from the Filesystem

難度: Medium

## 問題描述

Given a list of folders, remove all sub-folders in those folders and return in **any order** the folders after removing.

f a `folder[i]` is located within another `folder[j]`, it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: `/` followed by one or more lowercase English letters. For example, `/leetcode` and `/leetcode/problems` are valid paths while an empty string and `/` are not.

Example 1:

```
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
```

Constraints:

- `1 <= folder.length <= 4 * 10^4`
- `2 <= folder[i].length <= 100`
- `folder[i] contains only lowercase letters and '/'`
- `folder[i] always starts with character '/'`
- `Each folder name is unique.`


---
## 解決思路

此題首先需要按照`folder`中字串的長度來做遞增排序，之後需要用`unordered_set<string>`來記錄合法的目錄。在遍歷時我們需要針對每一個`folder[i]`中的所有子目錄階層來判斷是否已經存在於set中，若有子目錄階層已經被儲存過，則`folder[i]`不合法，否則`folder[i]`為一個合法獨特目錄，我們將之存進set中。最後只要將set中所有的目錄存成`vector<string>`形式返回即可。

