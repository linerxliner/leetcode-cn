// Mathmetical method.
// Time: O(K * logN), Space: O(1)

class Solution:    
    def superEggDrop(self, K: int, N: int) -> int:
        def f(t):
            result = 0
            c = 1

            for k in range(K):
                c *= (t - k) / (k + 1)
                result += c
                if result >= N:
                    break
                
            return result
        
        lo = 1
        hi = N + 1
        
        while lo < hi:
            mi = (lo + hi) >> 1
            
            if f(mi) < N:
                lo = mi + 1
            else:
                hi = mi
        
        return lo

