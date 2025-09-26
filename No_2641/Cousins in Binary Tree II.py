# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root

        queue = deque([root])
        root.val = 0

        while queue:
            size = len(queue)
            level_sum = 0
            child_sum = {}

            for _ in range(size):
                node = queue.popleft()
                total = 0
                if node.left:
                    total += node.left.val
                if node.right:
                    total += node.right.val
                if node.left or node.right:
                    child_sum[node] = total
                level_sum += total
                queue.append(node)

            for _ in range(size):
                node = queue.popleft()
                sibling_sum = child_sum.get(node, 0)
                if node.left:
                    node.left.val = level_sum - sibling_sum
                    queue.append(node.left)
                if node.right:
                    node.right.val = level_sum - sibling_sum
                    queue.append(node.right)

        return root