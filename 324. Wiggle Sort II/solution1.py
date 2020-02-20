class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def actual_idx(idx):
            return (1 + 2 * idx) % (length | 1)
        
        if len(nums) < 2:
            return nums
        
        length = len(nums)
        median = heapq.nlargest(length // 2, nums)[-1]
        
        lo = 0
        hi = length - 1
        probe = 0
        
        while probe <= hi:
            if nums[actual_idx(probe)] > median:
                nums[actual_idx(lo)], nums[actual_idx(probe)] = nums[actual_idx(probe)], nums[actual_idx(lo)]
                lo += 1
                probe += 1
            elif nums[actual_idx(probe)] < median:
                nums[actual_idx(hi)], nums[actual_idx(probe)] = nums[actual_idx(probe)], nums[actual_idx(hi)]
                hi -= 1
            else:
                probe += 1
        
        return nums
