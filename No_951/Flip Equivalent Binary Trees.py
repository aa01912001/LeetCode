# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def check(node1: Optional[TreeNode], node2: Optional[TreeNode]) -> bool:
            if node1 is None and node2 is None:
                return True
            elif (node1 is None) or (node2 is None) or (node1.val != node2.val):
                return False
            
            children1 = [node1.left, node1.right]
            children2 = [node2.left, node2.right]
            children1.sort(key=lambda x: x.val if x is not None else -1)
            children2.sort(key=lambda x: x.val if x is not None else -1)
            
            return check(children1[0], children2[0]) and check(children1[1], children2[1])
        
        
        return check(root1, root2)
            
            