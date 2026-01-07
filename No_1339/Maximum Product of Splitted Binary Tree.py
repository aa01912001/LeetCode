# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        MOD = 10**9 + 7
        max_product = 0

        def compute_total_sum(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            return (
                node.val
                + compute_total_sum(node.left)
                + compute_total_sum(node.right)
            )

        def postorder_sum(node: Optional[TreeNode]) -> int:
            nonlocal max_product
            if not node:
                return 0

            subtree_sum = (
                node.val
                + postorder_sum(node.left)
                + postorder_sum(node.right)
            )

            max_product = max(
                max_product,
                subtree_sum * (total_sum - subtree_sum)
            )

            return subtree_sum

        total_sum = compute_total_sum(root)
        postorder_sum(root)

        return max_product % MOD

        