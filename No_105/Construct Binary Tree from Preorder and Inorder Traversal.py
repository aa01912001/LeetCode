# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        
        i = 0
        while preorder[0] != inorder[i]:
            i += 1
            
        root = TreeNode(inorder[i])
        root.left = self.buildTree(preorder[1:1+i], inorder[0:i])
        root.right = self.buildTree(preorder[1+i:], inorder[i+1:])
        
        return root