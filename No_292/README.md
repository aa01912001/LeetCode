題號: 292. Nim Game

難度: Easy

## 問題描述

You are playing the following Nim Game with your friend:

- Initially, there is a heap of stones on the table.
- You and your friend will alternate taking turns, and **you go first**.
- On each turn, the person whose turn it is will remove 1 to 3 stones from the heap.
- The one who removes the last stone is the winner.

Given `n`, the number of stones in the heap, return `true` if you can win the game assuming both you and your friend play optimally, otherwise return `false`.

Example 1:

```
Input: n = 4
Output: false
Explanation: These are the possible outcomes:
1. You remove 1 stone. Your friend removes 3 stones, including the last stone. Your friend wins.
2. You remove 2 stones. Your friend removes 2 stones, including the last stone. Your friend wins.
3. You remove 3 stones. Your friend removes the last stone. Your friend wins.
In all outcomes, your friend wins.
```

Constraints:

- 1 <= n <= 2^31 - 1



---
## 解決思路

透過觀察當`n`為1、2、3時你必贏，`n`為4時你必輸;而`n`為5、6、7時你可以避免自己淪落到`n`為4的場景，但當`n`為8時，你無法避免對手會讓你遇到`n`為4的情況。所以如此推論下去當`n`為4、8、12、16、...時你必輸。因此我們只要判斷輸入的`n`值是否為4的倍數即可。