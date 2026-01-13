"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        ans = []
        def dfs(node):
            if not node:
                return

            ans.append(node.val)
            for c in node.children or []:
                dfs(c)
        
        dfs(root)
        return ans