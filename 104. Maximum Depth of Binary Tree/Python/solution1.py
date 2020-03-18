# Complexity
#   Time: O(v)
#   Space: O(v)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        max_depth, d = 0, 1
        curr = root
        stack = deque()

        while True:
            while curr:
                max_depth = max(max_depth, d)
                d += 1
                if curr.right:
                    stack.append((curr.right, d))
                curr = curr.left
            if len(stack) == 0:
                break
            curr, d = stack.pop()

        return max_depth
