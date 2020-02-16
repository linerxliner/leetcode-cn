class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = 0
        curr_n = -1
        
        for n in nums:
            if cnt == 0:
                curr_n = n
            
            if curr_n == n:
                cnt += 1
            else:
                cnt -= 1
        
        return curr_n

