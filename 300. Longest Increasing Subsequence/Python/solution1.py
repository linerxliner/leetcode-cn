// DP.
// Time: O(n * log(n)); Space: O(n)

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [-sys.maxsize]
        
        for n in nums:
            idx = bisect.bisect_right(dp, n)
            if dp[idx - 1] < n:
                if len(dp) <= idx:
                    dp.append(n)
                else:
                    dp[idx] = n
        
        return len(dp) - 1
