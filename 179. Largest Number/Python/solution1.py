class Solution:            
    def largestNumber(self, nums: List[int]) -> str:
        from functools import cmp_to_key
        
        def cmp(x, y):
            t1 = x + y
            t2 = y + x
            
            if t1 < t2:
                return 1
            elif t1 == t2:
                return 0
            else:
                return -1
        
        nums = list(map(lambda x: str(x), nums))
        nums.sort(key=cmp_to_key(cmp))
        result = ''.join(nums)
        
        return '0' if len(result) > 0 and result[0] == '0' else result
