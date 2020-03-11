# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        lcis = 0
        begin, end = 0, 1

        while end <= len(nums):
            if end == len(nums) or nums[end - 1] >= nums[end]:
                lcis = max(lcis, end - begin)
                begin = end
            end += 1

        return lcis
