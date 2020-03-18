# Complexity
#   Time: O(n!)
#   Space: O(n!)
# Description
#   Incremental generation by testing used elements.

class Solution:
    def generate_permutations(self, nums, d):
        if d == len(nums):
            self.result.append(self.answer[:])
            return

        for n in nums:
            if n not in self.used:
                self.used.add(n)
                self.answer[d] = n
                self.generate_permutations(nums, d + 1)
                self.used.remove(n)

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.result = []
        self.answer = [0] * len(nums)
        self.used = set()

        self.generate_permutations(nums, 0)

        return self.result
