# Complexity
#   Time: O(max(log(a), log(b)))
#   Space: O(1)

class Solution:
    MASK = 0xFFFFFFFF
    INT_MAX = 0x7FFFFFFF
    
    def getSum(self, a: int, b: int) -> int:
        while b != 0:
            c = (a & b) << 1
            a = (a ^ b) & self.MASK
            b = c & self.MASK
        return a if a <= self.INT_MAX else ~((a & self.INT_MAX) ^ self.INT_MAX)

