# Complexity
#   Time: O(n * log(n))
#   Space: O(n)

import math

class Solution:
    def countPrimes(self, n: int) -> int:
        primes = [0, 0] + [1] * (n - 2)
        
        for base in range(2, int(math.sqrt(n)) + 1):
            if primes[base]:
                for num in range(base * base, n, base):
                    primes[num] = 0
        
        return sum(primes)

