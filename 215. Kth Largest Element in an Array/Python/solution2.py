// BFPRT(Constant coefficient of time complexity is too large to use this algorithm in normal situation.)
// Time: O(n), Space: O(n)

class Solution:
    _Q = 5
    
    def trivial_select(self, nums, k):
        nums.sort(reverse=True)
        return nums[k]
    
    def BFPRT(self, nums, k):
        if len(nums) < self._Q:
            return self.trivial_select(nums, k)
        
        medians = []
        for begin in range(0, len(nums), self._Q):
            end = min(begin + self._Q, len(nums))
            medians.append(self.trivial_select(nums[begin:end], (end - begin) // 2))
        
        M = self.BFPRT(medians, len(medians) // 2)
        
        G = []
        E = []
        L = []
        
        for n in nums:
            if n > M:
                G.append(n)
            elif n == M:
                E.append(n)
            else:
                L.append(n)
        
        if k < len(G):
            return self.BFPRT(G, k)
        elif k < len(G) + len(E):
            return M
        else:
            return self.BFPRT(L, k - (len(G) + len(E)))
            
    
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k -= 1
        
        return self.BFPRT(nums, k)
