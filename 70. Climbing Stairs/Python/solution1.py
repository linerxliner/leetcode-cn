# Complexity
#   Time: O(n)
#   Space: O(1)
# Description
#   DP.

class Solution:
    def climbStairs(self, n: int) -> int:
        f, g = 0, 1

        for _ in range(n):
            f, g = g, f + g

        return g
