# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def search_path(self, root):
        if root == None:
            return 0
        
        left = self.search_path(root.left)
        right = self.search_path(root.right)
        
        self.max_path_sum = max(self.max_path_sum, left + root.val + right)
        
        return max(root.val + max(left, right), 0)
    
    def maxPathSum(self, root: TreeNode) -> int:
        self.max_path_sum = root.val
        self.search_path(root)
        
        return self.max_path_sum
