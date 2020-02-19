class Solution:
    def titleToNumber(self, s: str) -> int:
        num = 0
        
        for l in s:
            num *= 26
            num += ord(l) - ord('A') + 1
        
        return num
