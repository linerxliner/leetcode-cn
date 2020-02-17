// Backtrakcing with memo of bad suffix.
// Time: O(n^3), Space: O(n^2)

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        def break_one_word(begin):
            if begin == s_len:
                results.append(' '.join(solution))
                return True
            elif begin > s_len or not dp[begin]:
                return False
            
            matched = False
            
            for w in wordDict:
                end = begin + len(w)
                
                if end <= s_len and w == s[begin:end]:
                    solution.append(w)
                    if break_one_word(end):
                        matched = True
                    solution.pop()
            
            if not matched:
                dp[begin] = False
            return dp[begin]
        
        s_len = len(s)
        dp = [True] * s_len
        results = []
        solution = []
        
        break_one_word(0)
        
        return results
