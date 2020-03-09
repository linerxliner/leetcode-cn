# Complexity
#   Time: O(n * m)
#   Space: O(n * m)
# Description
#   Merge letters in same place.

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        prefix = ''

        for t in list(map(set, zip(*strs))):
            if len(t) > 1:
                break
            prefix += t.pop()

        return prefix
