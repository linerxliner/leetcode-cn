# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Binary search in an ascent sequence idetifying by nums[0] and nums[mi].

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1

        lo, hi = 0, len(nums) - 1

        while lo < hi:
            mi = (lo + hi) // 2

            if (nums[0] <= target) ^ (target <= nums[mi]) ^ (nums[mi] < nums[0]):
                lo = mi + 1
            else:
                hi = mi

        return lo if nums[lo] == target else -1
