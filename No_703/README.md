題號: 703. Kth Largest Element in a Stream

難度: Easy

## 問題描述
Design a class to find the `kth` largest element in a stream. Note that it is the `kth` largest element in the sorted order, not the kth distinct element.

Implement `KthLargest` class:
 
- `KthLargest(int k, int[] nums)` Initializes the object with the integer `k` and the stream of integers `nums`.
- `int add(int val)` Returns the element representing the `kth` largest element in the stream.

Example 1:
```
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
```

Note:

- `1 <= k <= 104`
- `0 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to `add`.
- It is guaranteed that there will be at least `k` elements in the array when you search for the `kth` element.

---
## 解決思路
此題我們可以利用min heap來儲存最大的k個元素，在`KthLargest`中的for loop，我們加入了`if(minHeap.size() > k) minHeap.pop()`讓heap可以只保持在儲存最大k個元素。而在`add`中，我們只要判斷heap中的元素數量是否小於k，或是val是否大於k個元素中最小的那一個，若符合上述條件之一，則允許val被插入到heap中，而插入後也要判斷heap元素是否超過k，若超過則pop heap中最小的那一個。最後`return minHeap.top()`即為kth largest number。