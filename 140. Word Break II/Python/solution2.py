// Dynamic programming with retrieving solutions.
// Time: O(n^3), Space: O(n^2)

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        s_len = len(s)
        dp = [[] for _ in range(s_len +1)]
        dp[0].append(-1)
        solution = []
        results = []
        
        for end in range(1, s_len + 1):
            for w in wordDict:
                begin = end - len(w)
                if begin >= 0 and w == s[begin:end] and len(dp[begin]) > 0:
                    dp[end].append(begin)
        
        def retrieve_results(end):
            if end == 0:
                results.append(' '.join(solution[::-1]))
                return
            
            for begin in dp[end]:
                solution.append(s[begin:end])
                retrieve_results(begin)
                solution.pop()
        
        retrieve_results(s_len)
        
        return results
