class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        if len(s) == 0 or len(s) < k:
            return 0
        
        counter = collections.Counter(s)
        
        begin = 0
        end = len(s) - 1
        
        while begin <= end and counter[s[begin]] < k:
            begin += 1
        while begin <= end and counter[s[end]] < k:
            end -= 1

        s = s[begin:end + 1]
        max_len = -1
        
        for i in range(len(s)):
            if counter[s[i]] < k:
                return max(self.longestSubstring(s[:i], k), self.longestSubstring(s[i + 1:], k))
        
        return max_len if max_len >= 0 else len(s)
