# Complexity
#   Time: O(n ^ 2) (K == 1), O(n) (K > 1)
#   Space: O(n ^ 2) (K == 1), O(n) (K > 1)

class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        if K == 1:
            return min(S[i:] + S[:i] for i in range(len(S)))
        else:
            result = ''
            cnt = [0] * 26

            for c in S:
                cnt[ord(c) - ord('a')] += 1

            for i, n in enumerate(cnt):
                result += chr(ord('a') + i) * n

            return result

