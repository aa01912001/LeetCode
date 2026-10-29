# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
	def countDominantNodes(self, root: TreeNode | None) -> int:
		ans = 0
		
		def dfs(node: TreeNode | None) -> int:
			nonlocal ans
			if node is None:
				return -1
			
			max_val = max(dfs(node.left), dfs(node.right))
			if node.val >= max_val:
				ans += 1
				max_val = node.val
				
			return max_val

		dfs(root)
		return ans