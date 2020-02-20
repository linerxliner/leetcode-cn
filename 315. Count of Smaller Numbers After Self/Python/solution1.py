// Divide and conquer.
// Time: O(nlogn), Space: O(n)

class Solution:
    def merge(self, lo, mi, hi):
        cnt = 0
        i, l, r = lo, 0, mi
        left_indexes = self.indexes[lo:mi]
        
        while l < mi - lo:
            if r >= hi or self.nums[left_indexes[l]] <= self.nums[self.indexes[r]]:
                self.indexes[i] = left_indexes[l]
                self.result[left_indexes[l]] += r - mi
                l += 1
            else:
                self.indexes[i] = self.indexes[r]
                r += 1
            i += 1
        
    def count(self, lo, hi):
        if hi - lo > 1:
            mi = (lo + hi) // 2
            self.count(lo, mi)
            self.count(mi, hi)
            self.merge(lo, mi, hi)
    
    def countSmaller(self, nums: List[int]) -> List[int]:
        self.indexes = [i for i in range(len(nums))]
        self.nums = nums
        self.result = [0] * len(nums)
        
        self.count(0, len(nums))
        
        return self.result
