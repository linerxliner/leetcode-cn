# DP with new perspective.
# Time: O(K * N), Space: O(K)

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        m = 0
        dp = [0] * (K + 1)
        
        while dp[K] < N:
            m += 1
            for k in range(K, 0, -1):
                dp[k] += dp[k - 1] + 1
        
        return m


