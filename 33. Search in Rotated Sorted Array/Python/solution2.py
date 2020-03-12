# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Binary search in an ascent sequence idetifying by nums[lo] and nums[mi].

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1

        lo, hi = 0, len(nums) - 1

        while lo < hi:
            mi = (lo + hi) // 2

            if nums[lo] <= nums[mi]:
                if nums[lo] <= target <= nums[mi]:
                    hi = mi
                else:
                    lo = mi + 1
            else:
                if nums[mi] <= target <= nums[hi]:
                    lo = mi
                else:
                    hi = mi - 1

        return lo if nums[lo] == target else -1
