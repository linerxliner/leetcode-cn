# Complexity
#   Time: O(n * 2 ^ n)
#   Space: O(2 ^ n)
# Description
#   Bitmap generation.

class Solution:
    def generate_subsets(self, nums, d):
        if d == len(nums):
            answer = []
            for i, b in enumerate(self.bits):
                if b:
                    answer.append(nums[i])
            self.result.append(answer)
            return

        self.generate_subsets(nums, d + 1)
        self.bits[d] = True
        self.generate_subsets(nums, d + 1)
        self.bits[d] = False

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.result = []
        self.bits = [False] * len(nums)

        self.generate_subsets(nums, 0)

        return self.result
