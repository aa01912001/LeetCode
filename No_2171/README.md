題號: 2171. Removing Minimum Number of Magic Beans

難度: Medium

## 問題描述
You are given an array of **positive** integers `beans`, where each integer represents the number of magic beans found in a particular magic bag.

**Remove** any number of beans (**possibly none**) from each bag such that the number of beans in each remaining **non-empty** bag (still containing **at least one** bean) is **equal**. Once a bean has been removed from a bag, you are not allowed to return it to any of the bags.

Return the **minimum** number of magic beans that you have to remove.

**Example 1:**
```
Input: beans = [4,1,6,5]
Output: 4
Explanation: 
- We remove 1 bean from the bag with only 1 bean.
  This results in the remaining bags: [4,0,6,5]
- Then we remove 2 beans from the bag with 6 beans.
  This results in the remaining bags: [4,0,4,5]
- Then we remove 1 bean from the bag with 5 beans.
  This results in the remaining bags: [4,0,4,4]
We removed a total of 1 + 2 + 1 = 4 beans to make the remaining non-empty bags have an equal number of beans.
There are no other solutions that remove 4 beans or fewer.
```

**Constraints:**

- `1 <= beans.length <= 10^5`
- `1 <= beans[i] <= 10^5`

**解決思路:**

此題我們可以先將beans做排序，並依序將每個元素`beans[i]`作為最終剩餘的數量來計算所需要的remove個數。

對於`beans[0]~beans[i-1]`我們應該要移除所有的數量(因為這數皆小於`beans[i]`)，而對於`beans[i+1]`之後的元素成本則為需要將其變為`beans[i]`所需扣除的數量。
