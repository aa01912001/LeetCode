# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        queue = deque([root])
        level = 0

        while queue:
            size = len(queue)
            nodes = [queue.popleft() for _ in range(size)]

            for node in nodes:
                if node.left:
                    queue.extend([node.left, node.right])

            if level % 2 == 1:
                values = [node.val for node in nodes][::-1]
                for node, val in zip(nodes, values):
                    node.val = val

            level += 1

        return root