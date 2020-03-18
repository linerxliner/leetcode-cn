# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        y, t = 0, x
        while t > 0:
            y *= 10
            y += t % 10
            t //= 10

        return x == y
