# Complexity
#    Time: O(1)
#    Space: O(1)

class Solution:
    def detect_segment(self, s, begin, d):
        if d == 4:
            if begin == len(s):
                self.result.append('.'.join(self.answer))
            return

        for end in range(begin + 1, min(len(s), begin + 3) + 1):
            if (end - begin == 1 or (end - begin > 1 and s[begin] != '0')) and int(s[begin:end]) <= 255:
                self.answer[d] = s[begin:end]
                self.detect_segment(s, end, d + 1)
            else:
                break

    def restoreIpAddresses(self, s: str) -> List[str]:
        self.result = []
        self.answer = [''] * 4

        self.detect_segment(s, 0, 0)

        return self.result
