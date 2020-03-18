# Complexity
#   Time: O(2 ^ n)
#   Space: O(2 ^ n)
# Description
#   Mirror flip with adding 1 to most significant bit.

class Solution:
    def grayCode(self, n: int) -> List[int]:
        result = [0]
        msb = 1

        for _ in range(n):
            result.extend([msb + code for code in reversed(result)])
            msb <<= 1

        return result
