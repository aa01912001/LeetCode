題號: 1041. Robot Bounded In Circle
難度: Medium

## 問題描述
On an infinite plane, a robot initially stands at `(0, 0)` and faces north. Note that:

- The **north direction** is the positive direction of the y-axis.
- The **south direction** is the negative direction of the y-axis.
- The **east direction** is the positive direction of the x-axis.
- The **west direction** is the negative direction of the x-axis.

The robot can receive one of three instructions:

- `"G"`: go straight 1 unit.
- `"L"`: turn 90 degrees to the left (i.e., anti-clockwise direction).
- `"R"`: turn 90 degrees to the right (i.e., clockwise direction).

The robot performs the `instructions` given in order, and repeats them forever.

Return `true` if and only if there exists a circle in the plane such that the robot never leaves the circle.

**Example 1:**
```
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot is initially at (0, 0) facing the north direction.
"G": move one step. Position: (0, 1). Direction: North.
"G": move one step. Position: (0, 2). Direction: North.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: West.
"L": turn 90 degrees anti-clockwise. Position: (0, 2). Direction: South.
"G": move one step. Position: (0, 1). Direction: South.
"G": move one step. Position: (0, 0). Direction: South.
Repeating the instructions, the robot goes into the cycle: (0, 0) --> (0, 1) --> (0, 2) --> (0, 1) --> (0, 0).
Based on that, we return true.
```
**Constraints:**

- `1 <= instructions.length <= 100`
- `instructions[i]` is `'G'`, `'L'` or, `'R'`.

## 解決思路
此題我們模擬`instructions`內的操作，並且判斷最後位置是否為原點，或是非面向北方即可。

Note: 只要最後不面向北方，至多經過4 round的操作，一定可形成一cycle。