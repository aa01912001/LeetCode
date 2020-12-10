題號: 1641. Count Sorted Vowel Strings

難度: Medium

## 問題描述
Given an integer `n`, return *the number of strings of length* `n` *that consist only of vowels (*`a`*,* `e`*,* `i`*,* `o`*,* `u`) and are **lexicographically sorted**.

A string `s` is **lexicographically sorted** if for all valid `i`, `s[i]` is the same as or comes before `s[i+1]` in the alphabet.

---
## 解決思路
此題相當於求n個相同球與4根相同棒子之排列方法數。

在排列後的pattern中，棒子相當於將球隔開並劃分為a、e、i、o、u區段

假設n為5，0為球，1為棒子。

Example:

**010101010** 此排列相當於 a、e、i、o、u。

**110110000** 此排列相當於 i、u、u、u、u。

**111100000** 此排列相當於 u、u、u、u、u。

**000001111** 此排列相當於 a、a、a、a、a。

**001100110** 此排列相當於 a、a、i、i、u。

又`n`個相同物與`m`個相同物之公式為: **(n+m)!/(n!m!)*。

所以此答案為(n+4)!/(n!4!)，化簡後為(n+4)(n+3)(n+2)(n+1)/24。