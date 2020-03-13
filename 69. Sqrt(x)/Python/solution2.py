# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Binary search.

class Solution:
    def mySqrt(self, x: int) -> int:
        lo, mi, hi = 0, 1, x

        while lo < hi:
            mi = (lo + hi + 1) // 2

            if mi ** 2 > x:
                hi = mi - 1
            else:
                lo = mi

        return lo
