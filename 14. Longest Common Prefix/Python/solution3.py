# Complexity
#   Time: O(n * m)
#   Space: O(m)
# Description
#   Scans all strs step by step.

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
        for i in range(0, len(strs[0])):
            if i == len(strs[0]):
                break
            else:
                c = strs[0][i]

            for s in strs[1:]:
                if i == len(s) or c != s[i]:
                    return prefix

            prefix += c

        return prefix
