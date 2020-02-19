// Stack of states.
// Time: O(n), Space: O(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    NONE_DISCOVERED = 0
    LEFT_DISCOVERED = 1
    BOTH_DISCOVERED = 2
    
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        stack = [[root, self.NONE_DISCOVERED]]
        one_found = False
        lca_idx = 0
        
        while len(stack) > 0:
            if stack[-1][1] == self.NONE_DISCOVERED:
                if stack[-1][0] == p or stack[-1][0] == q:
                    if one_found:
                        return stack[lca_idx][0]
                    else:
                        one_found = True
                        lca_idx = len(stack) - 1
                stack[-1][1] += 1
                if stack[-1][0].left:
                    stack.append([stack[-1][0].left, self.NONE_DISCOVERED])
            elif stack[-1][1] == self.LEFT_DISCOVERED:
                stack[-1][1] += 1
                if stack[-1][0].right:
                    stack.append([stack[-1][0].right, self.NONE_DISCOVERED])
            else:
                if lca_idx == len(stack) - 1:
                    lca_idx -= 1
                stack.pop()
        
        return None
