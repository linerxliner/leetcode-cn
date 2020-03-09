# Complexity
#   Time: O(n)
#   Time: O(n)

class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) > len(s2):
            return False

        s1_cnt, s2_cnt = {}, {}
        s1_len, win_len = len(s1), 0

        for c in s1:
            s1_cnt[c] = s1_cnt.get(c, 0) + 1

        for r in range(0, len(s2)):
            c = s2[r]
            if c in s1_cnt:
                s2_cnt[c] = s2_cnt.get(c, 0) + 1
                win_len += 1
                l = r - win_len + 1
                while s2_cnt[c] > s1_cnt[c]:
                    s2_cnt[s2[l]] -= 1
                    l += 1
                    win_len -= 1
                if win_len == s1_len:
                    return True
            else:
                s2_cnt.clear()
                win_len = 0

        return False
