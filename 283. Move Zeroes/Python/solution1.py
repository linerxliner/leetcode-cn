class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero_head = 0
        
        for zero_tail in range(len(nums)):
            if nums[zero_tail] != 0:
                nums[zero_head], nums[zero_tail] = nums[zero_tail], nums[zero_head]
                zero_head += 1
            
