Problem Number: 331. Verify Preorder Serialization of a Binary Tree

Difficulty: `Medium`

## Problem Description

One way to serialize a binary tree is to use **preorder traversal**. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as `"#"`.

![圖片](https://hackmd.io/_uploads/ryY2JHfTzl.png)


For example, the above binary tree can be serialized to the string `"9,3,4,#,#,1,#,#,2,#,6,#,#"`, where `"#"` represents a null node.

Given a string of comma-separated values `preorder`, return `true` if it is a correct preorder traversal serialization of a binary tree.

It is **guaranteed** that each comma-separated value in the string must be either an integer or a character `"#"` representing null pointer.

You may assume that the input format is always valid.

* For example, it could never contain two consecutive commas, such as `"1,,3"`.

**Note:** You are not allowed to reconstruct the tree.


**Example 1:**
```
Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
```
**Constraints:**

- `1 <= preorder.length <= 10^4`
- `preorder` consist of integers in the range `[0, 100]` and `'#'` separated by commas `','`.

**Intuition:**

In any valid binary tree, the number of external nodes (or null nodes `#`) is always equal to the number of internal nodes plus one.

When we do a preorder traversal, we can track this relationship using a running score:

- We add 1 when encountering an internal node.

- We subtract 1 when encountering a external node.

Because of the tree's structural constraints, the cumulative score will never drop below -1 during the traversal, and it will end at -1 once the tree is fully validated.