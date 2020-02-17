class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_count = [0] * 26
        t_count = [0] * 26
        
        for l in s:
            s_count[ord(l) - ord('a')] += 1
        for l in t:
            t_count[ord(l) - ord('a')] += 1
        
        for i in range(len(s_count)):
            if s_count[i] != t_count[i]:
                return False
        
        return True
