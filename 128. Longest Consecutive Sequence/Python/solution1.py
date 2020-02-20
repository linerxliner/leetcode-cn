class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        max_len = 0
        
        for n in nums:
            if n - 1 not in nums:
                len_cnt = 1
                
                while n + 1 in nums:
                    len_cnt += 1
                    n += 1
                
                max_len = max(max_len, len_cnt)
        
        return max_len
