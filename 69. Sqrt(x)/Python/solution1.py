# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Newton's method.

class Solution:
    def mySqrt(self, x: int) -> int:
        r, prev_r = 1, 0

        while abs(r - prev_r) > 0.01:
            prev_r = r
            r -= (r - x / r) / 2

        return int(r)
