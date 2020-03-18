# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    INT_MAX = 2 ** 31 - 1
    INT_MIN = -2 ** 31

    def reverse(self, x: int) -> int:
        positive = True
        if x < 0:
            positive = False
            x = -x

        y = 0
        while x != 0:
            y *= 10
            if positive:
                y += x % 10
            else:
                y -= x % 10
            x //= 10
            if (positive and y > self.INT_MAX) or (not positive and y < self.INT_MIN):
                return 0

        return y
