題號: 165. Compare Version Numbers

難度: Medium

## 問題描述
Given two **version strings**, `version1` and `version2`, compare them. A version string consists of **revisions** separated by dots `'.'`. The `value of the revision` is its **integer conversion** ignoring leading zeros.

To compare version strings, compare their revision values in **left-to-right order**. If one of the version strings has fewer revisions, treat the missing revision values as `0`.

Return the following:

- If `version1 < version2`, return -1.
- If `version1 > version2`, return 1.
- Otherwise, return 0.


**Example 1:**
```
Input: version1 = "1.2", version2 = "1.10"

Output: -1

Explanation:

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.
```

**Constraints:**

- `1 <= version1.length, version2.length <= 500`
- `version1` and `version2` only contain digits and` '.'`.
- `version1` and `version2` **are valid version numbers**.
- All the given revisions in `version1` and `version2` can be stored in a **32-bit integer**.

**解決思路:**

我們只需要分別將`version1`與`version2`根據`'.'`做字串split之後，再將長度較短的補0即可依序進行比較。