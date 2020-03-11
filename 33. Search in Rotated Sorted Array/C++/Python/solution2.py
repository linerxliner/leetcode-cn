# Complexity
#   Time: O(log(n))
#   Space: O(1)
# Description
#   Binary search in an ascent sequence idetifying by nums[lo] and nums[mi].

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lo, hi = 0, len(nums) - 1

        while lo <= hi:
            mi = (lo + hi) // 2

            if nums[lo] < nums[mi]:
                if nums[lo] <= target <= nums[mi]:
                    hi = mi
                else:
                    lo = mi + 1
            elif nums[lo] > nums[mi]:
                if nums[mi] <= target <= nums[hi]:
                    lo = mi
                else:
                    hi = mi - 1
            else:
                if nums[lo] == target:
                    return lo
                elif nums[hi] == target:
                    return hi
                else:
                    return -1

        return -1
