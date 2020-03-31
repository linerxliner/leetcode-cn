# Complexity
#   Time: O(k * n)
#   Space: O(k)

class Solution:
    MOD = 10 ** 9 + 7

    def kInversePairs(self, n: int, k: int) -> int:
        if k == 0:
            return 1

        ip_num = n * (n - 1) // 2
        if k > ip_num:
            return 0
        elif k > ip_num // 2:
            k = ip_num - k

        prev_dp, curr_dp = [0] * (k + 1), [0] * (k + 1)
        prev_dp[0] = curr_dp[0] = 1

        for i in range(2, n + 1):
            for j in range(1, k + 1):
                curr_dp[j] = (curr_dp[j - 1] + prev_dp[j]) % self.MOD
                if j >= i:
                    curr_dp[j] = (curr_dp[j] - prev_dp[j - i] + self.MOD) % self.MOD
            prev_dp, curr_dp = curr_dp, prev_dp

        return prev_dp[k]


