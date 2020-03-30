# Complexity
#   Time: O(v)
#   Space: O(v)
# Description
#   Highest leaf visible from left.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def goto_hlvfl(self, s):
        while len(s) > 0 and s[-1] != None:
            x = s[-1]
            if x.left:
                if x.right:
                    s.append(x.right)
                s.append(x.left)
            else:
                s.append(x.right)
        s.pop()

    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        result = []
        s = []
        x = root

        s.append(x)

        while len(s) > 0:
            if x != s[-1].left and x != s[-1].right:
                self.goto_hlvfl(s)
            x = s.pop()
            result.append(x.val)

        return result
