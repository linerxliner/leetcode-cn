# Complexity
#   Time: O(log(n))
#   Space: O(1)

class Solution:
    def trailingZeroes(self, n: int) -> int:
        cnt = 0
        
        while n > 0:
            cnt += n // 5
            n //= 5
        
        return cnt
