# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        lost = len(nums)
        
        for i, n in enumerate(nums):
            lost ^= i ^ n
        
        return lost
