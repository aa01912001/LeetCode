# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = 0
        def dfs(node, max_val):
            nonlocal ans
            if node is None:
                return
            if node.val >= max_val:
                ans += 1
            
            dfs(node.left, max(max_val, node.val))
            dfs(node.right, max(max_val, node.val))

        dfs(root, root.val)
        return ans