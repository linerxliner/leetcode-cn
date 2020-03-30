# Complexity
#   Time: O(v)
#   Space: O(v)
# Description
#   Morris Traversal.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def right_chain_traversal(self, x, result):
        prev_len = len(result)

        while x:
            result.append(x.val)
            x = x.right

        result[prev_len:] = result[prev_len:][::-1]

    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        result = []
        x = root

        while x:
            if x.left:
                t = x.left
                while t.right and t.right != x:
                    t = t.right
                if t.right:
                    t.right = None
                    self.right_chain_traversal(x.left, result)
                    x = x.right
                else:
                    t.right = x
                    x = x.left
            else:
                x = x.right
        self.right_chain_traversal(root, result)

        return result
