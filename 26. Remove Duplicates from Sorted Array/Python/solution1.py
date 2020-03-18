# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        last = 1

        for probe in range(1, len(nums)):
            if nums[last - 1] != nums[probe]:
                nums[last] = nums[probe]
                last += 1

        return last
