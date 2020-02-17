// Quick select.
// Time: AVG O(n), MAX O(n^2); Space: O(1)

class Solution:
    _Q = 5
    def findKthLargest(self, nums: List[int], k: int) -> int:
        lo = 0
        hi = len(nums) - 1
        k -= 1
        
        while lo < hi:
            l = lo
            r = hi
            ex = random.randint(l, r)
            nums[l], nums[ex] = nums[ex], nums[l]
            pivot = nums[l]
            
            while l < r:
                while l < r and pivot >= nums[r]:
                    r -= 1
                nums[l] = nums[r]
                while l < r and nums[l] >= pivot:
                    l += 1
                nums[r] = nums[l]
            nums[l] = pivot
            
            if l < k:
                lo = l + 1
            elif k < l:
                hi = l - 1
            else:
                break
        
        return nums[k]
