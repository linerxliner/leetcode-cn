class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        
        prev_prev = max(nums)
        prev = max(nums)
        
        for n in nums:
            if prev < n:
                return True
            elif prev_prev < n:
                prev = n
            else:
                prev_prev = n
        
        return False
