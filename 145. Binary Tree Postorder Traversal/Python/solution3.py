# Complexity
#   Time: O(v)
#   Space: O(v)
# Description
#   Transfers VRL (preorder) to LRV (postorder).

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
        s = []
        x = root

        while True:
            while x:
                result.append(x.val)
                if x.left:
                    s.append(x.left)
                x = x.right
            if len(s) == 0:
                break
            x = s.pop()

        return result[::-1]
