class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) <= 2:
            return max(nums)
        
        dp = [nums[0], max(nums[:2])]
        
        for m in nums[2:]:
            dp.append(max(dp[-1], dp[-2] + m))
        
        return dp[-1]


