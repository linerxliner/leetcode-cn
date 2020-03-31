# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        if len(start) != len(end) or start.replace('X', '') != end.replace('X', ''):
            return False

        i, j, n = 0, 0, len(start)
        while i < n and j < n:
            while i < n and start[i] == 'X':
                i += 1
            while j < n and end[j] == 'X':
                j += 1
            if i >= n or j >= n:
                break
            if start[i] == 'L' and i < j or start[i] == 'R' and j < i:
                return False
            i += 1
            j += 1

        return True


