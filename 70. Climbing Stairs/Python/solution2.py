# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Fabonacci number got by matrix.

import numpy as np

class Solution:
    def climbStairs(self, n: int) -> int:
        r = np.array([[1, 0], [0, 1]])
        a = np.array([[1, 1], [1, 0]])

        while n > 0:
            if n & 1 == 1:
                r = r.dot(a)
            a = a.dot(a)
            n >>= 1

        return int(r[0, 0])
