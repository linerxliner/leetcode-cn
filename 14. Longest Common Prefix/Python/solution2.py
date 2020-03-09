# Complexity
#   Time: O(n * m)
#   Space: O(m)
# Description
#   Compares min str between max str.

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
        elif len(strs) == 1:
            return strs[0]

        prefix = ''
        min_str = min(strs)
        max_str = max(strs)

        for i in range(0, min(len(min_str), len(max_str))):
            if min_str[i] != max_str[i]:
                break
            prefix += min_str[i]

        return prefix
