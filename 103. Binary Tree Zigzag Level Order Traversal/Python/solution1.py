# Complexity
#   Time: O(n)
#   Space: O(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        result = []

        dq = deque()
        from_l_to_r = True

        if root:
            dq.append(root)

        while len(dq) > 0:
            layer = []
            dq_len = len(dq)

            while dq_len > 0:
                dq_len -= 1
                if from_l_to_r:
                    tn = dq.popleft()
                    layer.append(tn.val)
                    if tn.left:
                        dq.append(tn.left)
                    if tn.right:
                        dq.append(tn.right)
                else:
                    tn = dq.pop()
                    layer.append(tn.val)
                    if tn.right:
                        dq.appendleft(tn.right)
                    if tn.left:
                        dq.appendleft(tn.left)

            result.append(layer)
            from_l_to_r = not from_l_to_r

        return result
