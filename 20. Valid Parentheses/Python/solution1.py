# Complexity
#   Time: O(n)
#   Space: O(n)

from collections import deque

class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()
        match = {')': '(', ']': '[', '}': '{'}

        for c in s:
            if c in ('(', '[', '{'):
                stack.append(c)
            else:
                if len(stack) == 0 or stack[-1] != match[c]:
                    return False
                else:
                    stack.pop()

        return len(stack) == 0
