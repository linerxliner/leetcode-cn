# Complexity
#   Time: O(n * (n - m) ^ 2)
#   Space: O(n)
# Description
#   DP.

class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        if m == 1:
            return sum(nums)

        n = len(nums)
        dp = [0] * (len(nums) + 1)

        for j, num in enumerate(nums):
            dp[j + 1] = dp[j] + num

        for i in range(2, m + 1):
            for j in range(n - m + i, i - 1, -1):
                total = 0
                for k in range(1, j - i + 2):
                    total += nums[j - k]
                    dp[j] = min(dp[j], max(dp[j - k], total))

        return dp[-1]


