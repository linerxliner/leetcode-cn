// Dynamic programming.
// Time: O(n), Space: O(n)

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) * k == 0:
            return []
        elif len(nums) <= k:
            return [max(nums)]
        
        to_right_dp = [nums[0]] * len(nums)
        to_left_dp = [nums[-1]] * len(nums)
        result = []
        
        for i in range(1, len(nums)):
            if i % k == 0:
                to_right_dp[i] = nums[i]
            else:
                to_right_dp[i] = max(to_right_dp[i - 1], nums[i])
        
        for i in range(len(nums) - 2, -1, -1):
            if (i + 1) % k == 0:
                to_left_dp[i] = nums[i]
            else:
                to_left_dp[i] = max(to_left_dp[i + 1], nums[i])
        
        left = 0
        right = min(k, len(nums)) - 1
        
        while right < len(nums):
            result.append(max(to_left_dp[left], to_right_dp[right]))
            left += 1
            right += 1
            
        return result
