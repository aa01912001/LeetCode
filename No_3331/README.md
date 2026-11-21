Problem Number: 3331. Find Subtree Sizes After Changes

Difficulty: `Medium`

## Problem Description

You are given a tree rooted at node 0 that consists of `n` nodes numbered from `0` to `n - 1`. The tree is represented by an array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node 0 is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

We make the following changes on the tree **one time simultaneously** for all nodes `x` from `1` to `n - 1`:

* Find the **closest** node `y` to node `x` such that `y` is an ancestor of `x`, and `s[x] == s[y]`.
* If node `y` does not exist, do nothing.
* Otherwise, **remove** the edge between `x` and its current parent and make node `y` the new parent of `x` by adding an edge between them.

Return an array `answer` of size `n` where `answer[i]` is the **size** of the subtree rooted at node `i` in the **final** tree.

**Example 1:**
![圖片](https://hackmd.io/_uploads/HJH86qC0Mg.png)

```
Input: parent = [-1,0,0,1,1,1], s = "abaabc"

Output: [6,3,1,1,1,1]

Explanation:

The parent of node 3 will change from node 1 to node 0.
```
**Constraints:**

* `n == parent.length == s.length`
* $1 \le n \le 10^5$
* `0 <= parent[i] <= n - 1` for all `i >= 1`.
* `parent[0] == -1`
* `parent` represents a valid tree.
* `s` consists only of lowercase English letters.


## Solution Intuition

We can first build the tree from `parent` as an **adjacency** list. Then, we traverse the tree using DFS, updating each node's parent by tracking `closest_ancestor` in a top-down manner (with backtracking to avoid unnecessary copying).

Once we obtain the updated `parent` array, we rebuild the tree and calculate the size of each subtree via DFS.