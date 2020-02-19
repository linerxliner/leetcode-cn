// Finds LCA indicated by two subtrees using recursion.
// Time: O(n), Space: O(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def search(self, root, p, q):
        root_found = root == p or root == q
        
        left_found = self.search(root.left, p, q) if root.left else False
        right_found = self.search(root.right, p, q) if root.right else False
        
        if int(root_found) + int(left_found) + int(right_found) >= 2 and self.lca is None:
            self.lca = root
        
        return root_found or left_found or right_found
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.lca = None
        
        self.search(root, p, q)
        
        return self.lca
