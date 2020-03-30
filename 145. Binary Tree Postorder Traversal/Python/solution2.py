# Complexity
#   Time: O(v)
#   Space: O(v)
# Description
#   Double stack pushing.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        result = []
        s = [root, root]

        while s:
            x = s.pop()
            if s and x == s[-1]:
                if x.right:
                    s.extend([x.right, x.right])
                if x.left:
                    s.extend([x.left, x.left])
            else:
                result.append(x.val)

        return result
