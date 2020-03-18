# Complexity
#   Time: O(n * (2 ^ n))
#   Space: O(2 ^ n)
# Description
#  Appends elements to existing subsets.

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]

        for n in nums:
            result.extend([subset + [n] for subset in result])

        return result
