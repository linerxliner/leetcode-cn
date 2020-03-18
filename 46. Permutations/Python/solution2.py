# Complexity
#   Time: O(n!)
#   Space: O(n!)
# Description
#   Incremental generation by swapping elements.

class Solution:
    def generate_permutations(self, nums, d):
        if d == len(nums):
            self.result.append(nums[:])
            return

        for i in range(d, len(nums)):
            nums[d], nums[i] = nums[i], nums[d]
            self.generate_permutations(nums, d + 1)
            nums[d], nums[i] = nums[i], nums[d]

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.result = []

        self.generate_permutations(nums, 0)

        return self.result
