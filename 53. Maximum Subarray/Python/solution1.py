# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0

        max_sum = nums[0]
        prev_sum = 0

        for n in nums:
            max_sum = max(max_sum, prev_sum + n)
            prev_sum = max(0, prev_sum + n)

        return max_sum
