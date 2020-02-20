class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums) - 1
        
        while lo < hi:
            mi = (lo + hi) // 2
            if nums[mi] < nums[mi + 1]:
                lo = mi + 1
            else:
                hi = mi
        
        return lo
