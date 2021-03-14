題號: 1436. Destination City

難度: Easy

## 問題描述
You are given the array `paths`, where `paths[i] = [cityAi, cityBi]` means there exists a direct path going from `cityAi` to `cityBi`. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
Example 1:

```
Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
```

Constraints:

- `1 <= paths.length <= 100`
- `paths[i].length == 2`
- `1 <= cityAi.length, cityBi.length <= 10`
- `cityAi != cityBi`
- All strings consist of lowercase and uppercase English letters and the space character.


---
## 解決思路

此題可利用unordered_map的結構來儲存每個city是否出現過，第一次遍歷`paths`時，預設將出現在`paths[i][1]`的city之value設為0(表示為destination);第二次遍歷`paths`時，將出現在`paths[i][0]`的city之value設為-1(表示不可能是destination)。最後只要找出value為0的city即為解答。
