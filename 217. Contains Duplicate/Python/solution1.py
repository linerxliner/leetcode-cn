// Compares adjacent elements after sorting.
// Time: O(nlogn), Space: O(1)

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:            
        nums.sort()
        
        for i in range(1, len(nums)):
            if nums[i - 1] == nums[i]:
                return True
            
        return False
