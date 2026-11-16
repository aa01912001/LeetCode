Problem Number: 3784. Minimum Deletion Cost to Make All Characters Equal

Difficulty: `Medium`

## Problem Description

You are given a string `s` of length `n` and an integer array `cost` of the same length, where `cost[i]` is the cost to **delete** the `iᵗʰ` character of `s`.

You may delete any number of characters from `s` (possibly none), such that the resulting string is **non-empty** and consists of **equal** characters.

Return an integer denoting the **minimum** total deletion cost required.

**Example 1:**
```
Input: s = "aabaac", cost = [1,2,3,4,1,10]

Output: 11

Explanation:

Deleting the characters at indices 0, 1, 2, 3, 4 results in the string "c", which consists of equal characters, and the total cost is cost[0] + cost[1] + cost[2] + cost[3] + cost[4] = 1 + 2 + 3 + 4 + 1 = 11.
```
**Constraints:**

- `n == s.length == cost.length`
- `1 <= n <= 10^5`
- `1 <= cost[i] <= 10^9`
- `s` consists of lowercase English letters.

## Solution Intuition

We need to sum up the cost for every character **separately** so that we can know the total cost associated with each character.

Assuming we want character `ch` to be the only character in the **final** string, the **total deletion** cost will be:

`sum(cost) - total cost of character ch`

Therefore, to minimize the deletion cost, we can get our answer using the following formula:

`sum(cost) - max(total cost for each unique character)`