# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        begin = -1
        max_len = 0
        last = {}

        for end in range(0, len(s)):
            if s[end] in last and begin < last[s[end]]:
                begin = last[s[end]]
            max_len = max(max_len, end - begin)
            last[s[end]] = end

        return max_len
