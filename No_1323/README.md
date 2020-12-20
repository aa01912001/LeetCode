題號: 1323. Maximum 69 Number

難度: Easy

## 問題描述
Given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing **at most** one digit (6 becomes 9, and 9 becomes 6).

Example 1:


```
Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666. 
The maximum number is 9969.
```

Example 2:


```
Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
```
---
## 解決思路
只要用while迴圈找出最大位數的6是哪一位(儲存在last變數中)後，在將原本的值加上3*10^(last-1)即為答案。