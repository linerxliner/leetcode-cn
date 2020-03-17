# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prev_nums = {}

        for i, n in enumerate(nums):
            if target - n in prev_nums:
                return [prev_nums[target - n], i]
            prev_nums[n] = i
