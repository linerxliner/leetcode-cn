# Complexity
#   Time: O(n)
#   Space: O(n)

class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = '#'
        for c in s:
            t += c + '#'

        longest_left, longest_len = 0, 0
        center, right = 0, 0
        p = [0] * len(t)

        for i in range(len(t)):
            if i < right:
                p[i] = min(right - i, p[center - (i - center)])

            l, r = i - p[i] - 1, i + +p[i] + 1
            while l >= 0 and r <= len(t) - 1 and t[l] == t[r]:
                p[i] += 1
                l -= 1
                r += 1

            if p[i] + i > right:
                center = i
                right = p[i] + i

            if p[i] > longest_len:
                longest_len = p[i]
                longest_left = (i - p[i]) // 2

        return s[longest_left: longest_left + longest_len]
