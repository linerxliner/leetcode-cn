class Solution:
    def partition(self, count, k):
        lo = 0
        hi = len(count) - 1
        
        while lo < hi:
            l = lo
            r = hi
            ex = random.randint(l, hi)
            count[l], count[ex] = count[ex], count[l]
            pivot = count[l]
            
            while l < r:
                while l < r and count[r][1] <= pivot[1]:
                    r -= 1
                count[l] = count[r]
                while l < r and count[l][1] >= pivot[1]:
                    l += 1
                count[r] = count[l]
            count[l] = pivot
            
            if l < k:
                lo = l + 1
            elif k < l:
                hi = l - 1
            else:
                break
            
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        k -= 1
        max_frequent = 0
        count = {}
        result = []
        
        for n in nums:
            count[n] = count.get(n, 0) + 1
        
        count_list = list(count.items())
        self.partition(count_list, k)
        
        for c in count_list[:k + 1]:
            result.append(c[0])
        
        return result
