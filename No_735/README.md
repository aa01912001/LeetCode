題號: 735. Asteroid Collision
難度: Medium

## 問題描述
We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

**Example 1:**
```
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
```

**Constraints:**

- `2 <= asteroids.length <= 10^4`
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`

## 解決思路
此題我們只需要模擬所有行星的碰撞即可。

程式中我們利用`vector<int>`來儲存當前不會碰撞的所有行星，一旦新的向左飛的`asteroids[i]`行星進來，我們首先判斷vector中的所有行星是否同樣向左飛，若是的話，則將`asteroids[i]`加進至vector中，否則開始從vector尾端開始依序模擬行星碰撞。

最後只要返回我們的vector即可。
