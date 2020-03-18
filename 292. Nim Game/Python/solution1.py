# Complexity
#   Time: O(1)
#   Space: O(1)

class Solution:
    def canWinNim(self, n: int) -> bool:
        return n & 3 != 0
