題號: 781. Rabbits in Forest
難度: Medium

## 問題描述
There is a forest with an unknown number of rabbits. We asked n rabbits **"How many rabbits have the same color as you?"** and collected the answers in an integer array `answers` where `answers[i]` is the answer of the `ith` rabbit.

Given the array `answers`, return the minimum number of rabbits that could be in the forest.

**Example 1:**
```
Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
```

**Constraints:**

- `1 <= answers.length <= 1000`
- `0 <= answers[i] < 1000`

## 解決思路
此題我們只需要將相同回答的兔子盡可能算為相同顏色即可。

假設rabbit_1與rabbit_2的回答為5，我們就將其算為同組，因此目前回答數5的容量只剩下4個名額;假設rabbit_3、4、5、6、7同樣回答5，我們可以發現對於rabbit_7來說已經沒有位置容下它，因此我們應該將其視為與前6隻兔子不同顏色。

在程式中，我們只要利用hash map來記錄每個回答數的容量即可。