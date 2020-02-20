class Solution:            
    def largestNumber(self, nums: List[int]) -> str:
        def key(x):
            width = len(str(x))
            return x / (10 ** width - 1)
        
        nums = sorted(nums, key=key, reverse=True)
        result = ''.join(list(map(str, nums)))
        
        return '0' if len(result) > 0 and result[0] == '0' else result
