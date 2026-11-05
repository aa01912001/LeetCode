Problem Number: 1385. Find the Distance Value Between Two Arrays


Difficulty: `Easy`

## Problem Description

Given two integer arrays `arr1` and `arr2`, and the integer `d`, *return the distance value between the two arrays.*

The distance value is defined as the number of elements `arr1[i]` such that there is not any element `arr2[j]` where $|arr1[i]-arr2[j]| \le d$.

**Example 1:**
```
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation: 
For arr1[0]=4 we have: 
|4-10|=6 > d=2 
|4-9|=5 > d=2 
|4-1|=3 > d=2 
|4-8|=4 > d=2 
For arr1[1]=5 we have: 
|5-10|=5 > d=2 
|5-9|=4 > d=2 
|5-1|=4 > d=2 
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
```
**Constraints:**

- `1 <= arr1.length, arr2.length <= 500`
- `-1000 <= arr1[i], arr2[j] <= 1000`
- `0 <= d <= 100`

**Intuition:**

We can sort `arr2` first and use binary search for each element in `arr1` to find its lower bound in `arr2`. Then, we check the distances to the adjacent elements (the found element and the one right before it); if neither is within distance `d`, we increment our count.