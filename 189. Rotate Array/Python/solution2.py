// Loop replacement.
// Time: O(n), Space: O(1)

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums_len = len(nums)
        k %= nums_len
        
        begin = 0
        cnt = 0

        while cnt < nums_len:
            t = nums[begin]
            
            prev = begin
            curr = (begin - k + nums_len) % nums_len
            
            while curr != begin:
                nums[prev] = nums[curr]
                prev = curr
                curr = (curr - k + nums_len) % nums_len
                cnt += 1
            
            nums[prev] = t
            cnt += 1
            
            begin += 1
                
