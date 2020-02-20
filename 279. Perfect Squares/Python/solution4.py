// Lagrange's four-square theorem.
// Time: O(sqrt(n)), Space: O(1)

class Solution:
    def numSquares(self, n: int) -> int:
        while n % 4 == 0:
            n >>= 2
        
        if n - 7 >= 0 and (n - 7) & 7 == 0:
            return 4
        
        sqrt_n = int(math.sqrt(n))
        if sqrt_n * sqrt_n == n:
            return 1
        
        for i in range(sqrt_n, 0, -1):
            m = n - i * i
            k = int(math.sqrt(m))
            if k * k == m:
                return 2

        return 3
