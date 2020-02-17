// DP.
// Time: O(n * m), Space: O(n)

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        s_len = len(s)
        dp = [False] * (s_len + 1)
        dp[0] = True
        
        for end in range(1, s_len + 1):
            for w in wordDict:
                begin = end - len(w)
                if begin >= 0 and w == s[begin:end] and dp[begin]:
                    dp[end] = True
                    break
        
        return dp[-1]
