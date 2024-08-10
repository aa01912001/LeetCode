# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorder_traverse(self, root: TreeNode, l: list[int]):
        if not root:
            return
        
        self.inorder_traverse(root.left, l)
        l.append(root.val)
        self.inorder_traverse(root.right, l)
        
    def merge_sorted_list(self, l1: list[int], l2: list[int]):
        merged_list = []
        n1 = len(l1)
        n2 = len(l2)
        idx1 = 0
        idx2 = 0
        
        while idx1 < n1 and idx2 < n2:
            if l1[idx1] < l2[idx2]:
                merged_list.append(l1[idx1])
                idx1 += 1
            else:
                merged_list.append(l2[idx2])
                idx2 += 1
                
        merged_list = [*merged_list, *l1[idx1:], *l2[idx2:]]
        return merged_list
    
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        l1, l2 = [], []
        self.inorder_traverse(root1, l1)
        self.inorder_traverse(root2, l2)
        return self.merge_sorted_list(l1, l2)