class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        elif len(nums) == 1:
            return [0]
        
        product = 1
        result = [1] * len(nums)
        
        for i in range(len(nums) - 2, -1, -1):
            result[i] = nums[i + 1] * result[i + 1]
        
        left = 1
        for i in range(1, len(nums)):
            left *= nums[i - 1]
            result[i] *= left
        
        return result
        
