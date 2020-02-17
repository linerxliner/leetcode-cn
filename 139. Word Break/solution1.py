// Backtracking with memo of bad suffix.
// Time: O(n^2), Space: O(n)

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        def break_one_word(begin):
            if begin >= s_len:
                return True
            elif not dp[begin]:
                return False
            
            for word in wordDict:
                end = begin + len(word)
                if end <= s_len and s[begin : end] in wordDict and break_one_word(end):
                    return True
            dp[begin] = False
            return False
        
        s_len = len(s)
        dp = [True] * s_len
        
        return break_one_word(0)
