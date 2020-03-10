# Complexity
#   Time: O(n)
#   Space: O(1)

class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s.strip())

        last, probe = 0, 0
        while probe < len(s):
            s[last] = s[probe]
            while probe < len(s) - 1 and s[probe] == ' ' and s[probe + 1] == ' ':
                probe += 1
            last += 1
            probe += 1
        s = s[0:last]

        begin = 0
        for end in range(0, len(s) + 1):
            if end == len(s) or s[end] == ' ':
                s[begin:end] = reversed(s[begin:end])
                begin = end + 1

        return ''.join(reversed(s))

