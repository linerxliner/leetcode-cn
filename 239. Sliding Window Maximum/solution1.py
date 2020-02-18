// Deque storing local maximun.
// Time: O(n), Space: O(n)

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if len(nums) * k == 0:
            return []
        elif len(nums) == 1:
            return nums
        
        result = []
        deq = collections.deque()
        
        for i in range(len(nums)):
            if len(deq) > 0 and i - k == deq[0]:
                deq.popleft()
            while len(deq) > 0 and nums[deq[-1]] < nums[i]:
                deq.pop()
            deq.append(i)
            if i >= k - 1:
                result.append(nums[deq[0]])
        
        return result
