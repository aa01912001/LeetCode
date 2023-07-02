題號: 218. The Skyline Problem
難度: Hard

## 問題描述
A city's **skyline** is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the **skyline** formed by these buildings collectively.

The geometric information of each building is given in the array `buildings` where `buildings[i] = [lefti, righti, heighti]`:

- `lefti` is the x coordinate of the left edge of the `ith` building.
- `righti` is the x coordinate of the right edge of the `ith` building.
- `heighti` is the height of the `ith` building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The **skyline** should be represented as a list of "key points" **sorted by their x-coordinate** in the form `[[x1,y1],[x2,y2],...]`. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

**Note:** There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...,[2 3],[4 5],[12 7],...]`

**Example 1:**
![](https://hackmd.io/_uploads/H1RgFOCO2.png)
```
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
```
**Constraints:**

- `1 <= buildings.length <= 10^4`
- `0 <= lefti < righti <= 2^31 - 1`
- `1 <= heighti <= 2^31 - 1`
- `buildings` is sorted by `lefti` in non-decreasing order.

## 解決思路
此題我們採用sweep line的方式先將每個`buildings[i]`分為兩個cases存入`vector<vector<int>> sweepPoints`:

1. `[lefti, heighti, 1]`
2. `[righti, heighti, 1]`

之後我們對`sweepPoints`做sorting，其中較左的點必須在前、left必須排在right前面，並且擁有高度較高的點也必須排在前面。

之後我們從頭遍歷`sweepPoints`，並利用`map<int, int> treeMap`來紀錄每個x軸的最高點為何。對於每個`sweepPoints[i]`來說，若:

- `sweepPoints[i]`為左點: 我們判斷如果該點高度為當前x軸之最高點，則此點必為key point。隨後我們將該點存入treeMap與解答中。

- `sweepPoints[i]`為右點: 首先先將該點的高度從treeMap扣除1，我們判斷如果該點高度為當前x軸之最高點，則此點可能為key point(之所以為可能的原因在於，同樣x軸上可能還會有高度較低的右點)，我們將該點存入解答中。

最後對於解答我們必須再進行一次過濾，以將上述同樣位於x軸的多點key points進行刪除，只留下最低點的。因此，若我們發現`ret[i][0] == ret[i+1][0]`，代表當前點會被後一個點取代，因此不列入最終解答。

