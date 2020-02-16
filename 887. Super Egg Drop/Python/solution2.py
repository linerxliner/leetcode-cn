# DP.
# Time: O(K * N), Space: O(N)

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        prev_dp = [i for i in range(0, N + 1)]
        
        for k in range(2, K + 1):
            x = 1
            curr_dp = [0]
            
            for n in range(1, N + 1):
                if x <= n and max(prev_dp[x - 1], curr_dp[n - x]) > max(prev_dp[x], curr_dp[n - x - 1]):
                    x += 1
                curr_dp.append(1 + max(prev_dp[x - 1], curr_dp[n - x]))
            
            prev_dp = curr_dp
        
        return prev_dp[N]

