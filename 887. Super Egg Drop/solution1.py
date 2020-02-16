# DP with binary search.
# Time: O(K * N * logN), Space: O(K * N)

class Solution:
    dp = {}
    
    def superEggDrop(self, K: int, N: int) -> int:
        if (K, N) in self.dp:
            return self.dp[(K, N)]
        elif K == 1:
            return N
        elif N == 0:
            return N
        
        lo = 1
        hi = N + 1
        
        while lo < hi:
            X = (lo + hi) >> 1
            
            if self.superEggDrop(K - 1, X - 1) - self.superEggDrop(K, N - X) < 0:
                lo = X + 1
            else:
                hi = X

        t1 = max(self.superEggDrop(K - 1, lo - 1), self.superEggDrop(K, N - lo))
        if lo > 1:
            t2 = max(self.superEggDrop(K - 1, lo - 2), self.superEggDrop(K, N - lo + 1))
        
        result = 1 + (min(t1, t2) if lo > 1 else t1)
        self.dp[(K, N)] = result
        
        return result


