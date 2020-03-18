# Complexity
#   Time: O(2 ^ n)
#   Space: O(2 ^ n)
# Description
#   Incremental generation.

class Solution:
    def generate_subsets(self, nums, begin, subset):
        self.result.append(subset[:])

        for i in range(begin, len(nums)):
            subset.append(nums[i])
            self.generate_subsets(nums, i + 1,  subset)
            subset.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.result = []

        self.generate_subsets(nums, 0, [])

        return self.result
